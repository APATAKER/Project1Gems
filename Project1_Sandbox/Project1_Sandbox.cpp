//this is a driver program to test your container library as you build it

#include<stl/vector/cSTLVector.h>
#include<stl/list/cSTLList.h>
#include<stl/map/cSTLMap.h>

#include<diy/list/cDIYList.h>
#include<iostream>

int main(int argc, char* argv[])
{	
	auto* container = new cSTLVector();
	iPersonContainer::sPerformanceData Pdata;

	iPersonContainer::sPerson person;
	person.unique_id = 1;
	person.first = "John";
	person.last = "Doe";
	person.age = 30;
	container->add_person(person);
	person.unique_id = 2;
	person.first = "Bam";
	person.last = "gore";
	person.age = 18;
	container->add_person(person);
	person.unique_id = 3;
	person.first = "willy";
	person.last = "Axe";
	person.age = 40;
	container->add_person(person);
	std::vector<iPersonContainer::sPerson> result;
	container->sort_people(iPersonContainer::e_sort_types::desc_id, result);
	container->get_last_call_performance(Pdata);
	iPersonContainer::sPerson res;
	container->find_person_by_id(2, res);
	std::cout << res.first << std::endl;
	/*for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i].first << std::endl;
	}*/
	
	container->get_last_call_performance(Pdata);
	delete container;
	
	return 0;
}

