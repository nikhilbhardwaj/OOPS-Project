#to create a sane package list that without aby redundancies
allpackages = ""

File.open('packageslist.txt','r') do | fptr |
  while line = fptr.gets
    package, version = line.split[0], line.split[1]
    allpackages << package + ","
  end
  allpackages = allpackages.split(',').uniq
end 

  puts "Total Packages : #{allpackages.length}"
  File.open('packages_list.txt','w') do |fptr|  
    (1..allpackages.length).each do |i|
      fptr.puts "#{i} #{allpackages[i-1]}"
    end
  end