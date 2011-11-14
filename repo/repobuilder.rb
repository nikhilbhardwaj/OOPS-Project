require 'rubygems'
require 'nokogiri'
require 'open-uri'


# additional code to make sure that we can resume after a break seamlessly
last_package = 0
File.open('lastbreak','r') { |fptr| last_package = fptr.gets.to_i }
puts "Resuming from package:#{last_package}" if last_package != 0

# to read each package from packageslist.txt and fetch the required info
# also to store this into a file that can easily be read by the c++ program
BASE_URL = "http://packages.debian.org/stable/"

File.open('packages_list.txt','r') do | fptr |
  while line = fptr.gets
    package_id = line.split[0].to_i
    package = line.split[1]
    dependencies = ""
    url = BASE_URL + package
    if package_id >= last_package
      doc = doc = Nokogiri::HTML(open(url))
      doc.css(".uldep a").each do |dependency|
        dependencies << dependency.text + ","
      end
      dependencies = dependencies.split(',').uniq.join(',')
      description = doc.css('#pdesc').text.strip
      version = ""
      unless doc.css('#content h1').text.strip.scan( /\(([^>]*)\)/).last.nil?
          version = doc.css('#content h1').text.strip.scan( /\(([^>]*)\)/).last.first
      end
    
      File.open("packages/#{package}","w") do |wfptr|
      wfptr.puts "PackageId:#{package_id}"
      wfptr.puts "Name:#{package}"
      wfptr.puts "Version:#{version}"
      wfptr.puts "Deps:#{dependencies}"
      end
      File.open("packages/#{package}.description",'w') {|wf| wf.write(description.capitalize)}
    
      package_id += 1
      puts "Now Processing #{package_id}"
      File.open('lastbreak','w') { |fptr| fptr.puts "#{package_id}" }
    end
  end
end

