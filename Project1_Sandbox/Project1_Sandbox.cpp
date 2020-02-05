//this is a driver program to test your container library as you build it

#include<stl/vector/cSTLVector.h>
#include<stl/list/cSTLList.h>
#include<stl/map/cSTLMap.h>

#include <diy/vector/cDIYVector.h>
#include <diy/map/cDIYMap.h>
#include<diy/list/cDIYList.h>
#include<iostream>

#include<random>
#include <functional>

//auto roll = std::bind(dist, rng);


int main(int argc, char* argv[])
{	
	auto* container = new cDIYMap();
	
	std::mt19937 rng{ std::random_device{}() };
	std::uniform_int_distribution<int> dist{ 0,999 };
	auto randomgen = [&rng, &dist]() {return  dist(rng); };

	for (int i = 0; i < 1000; i++)
	{
	iPersonContainer::sPerson person;
	person.unique_id = i;
	person.first = "John";
	person.last = "Doe";
	person.age = 30;
	//container->add_person(person);     // for vector and list
	container->add_person(std::to_string(i), person);  // for map
	}
	/*iPersonContainer::sPerson person;
	person.unique_id = 2;
	person.first = "Bam";
	person.last = "gore";
	person.age = 18;
	container->add_person(person);
	person.unique_id = 3;
	person.first = "willy";
	person.last = "Axe";
	person.age = 40;
	container->add_person(person);*/
	std::vector<iPersonContainer::sPerson> result;
	container->sort_people(iPersonContainer::e_sort_types::asc_id, result);
	container->get_last_call_performance(container->last_call_performance_);
	iPersonContainer::sPerson res;
	container->find_person_by_id(2, res);
	std::cout << std::endl<< res.first << std::endl;
	/*for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i].unique_id << std::endl;
	}*/
	
	container->get_last_call_performance(container->last_call_performance_);
	delete container;
	
	return 0;
}

