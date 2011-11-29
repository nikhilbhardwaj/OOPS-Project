all: package.o repository.o system.o packagemanager.o superpacker


superpacker: superpacker.cpp
	g++ concretepackage.o metapackage.o system.o repository.o packagemanager.o superpacker.cpp -o superpacker

package.o: concretepackage.cpp metapackage.cpp
	g++ -c concretepackage.cpp
	g++ -c metapackage.cpp

system.o: system.cpp
	g++ -c system.cpp

repository.o: repository.h repository.cpp
	g++ -c repository.cpp

packagemanager.o: packagemanager.cpp
	g++ -c packagemanager.cpp

clean:
	rm *.o superpacker
