//this is a driver program to test your container library as you build it

#include <stl/vector/cSTLVector.h>
#include<diy/list/cDIYList.h>

int main(int argc, char* argv[])
{	
	auto* container = new cDIYList();

	iPersonContainer::sPerson person;
	person.unique_id = 1;
	person.first = "John";
	person.last = "Doe";
	container->add_person(person);
	
	iPersonContainer::sPerson result;
	delete container;
	
	return 0;
}

