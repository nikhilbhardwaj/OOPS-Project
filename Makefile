all: superpacker


superpacker: superpacker.cpp
	g++ superpacker.cpp -o superpacker

package: concretepackage.cpp metapackage.cpp
	g++ -c concretepackage.cpp
	g++ -c metapackage.cpp

system: package
