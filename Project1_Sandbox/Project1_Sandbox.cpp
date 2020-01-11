//this is a driver program to test your container library as you build it

#include <stl/vector/cSTLVector.h>

int main(int argc, char* argv[])
{	
	auto* container = new cSTLVector();

	iPersonContainer::sPerson person;
	person.first = "John";
	person.last = "Doe";
	container->add_person(person);
	
	delete container;
	
	return 0;
}

