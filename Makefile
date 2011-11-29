all: package.o repository.o system.o superpacker


superpacker: superpacker.cpp
	g++ superpacker.cpp -o superpacker

package.o: concretepackage.cpp metapackage.cpp
	g++ -c concretepackage.cpp
	g++ -c metapackage.cpp

system.o: system.cpp
	g++ -c system.cpp

repository.o: repository.h repository.cpp
	g++ -c repository.cpp

packagemanager.o: packagemanager.cpp
	g++ -g repository.o system.o packagemanager.cpp concretepackage.o metapackage.o -o packagemanager
