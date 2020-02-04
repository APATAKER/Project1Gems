#include "cSTLMap.h"
#include<cmath>
#include <ctime>
#include <Windows.h>
#include <psapi.h>
#include<algorithm>
//#include<string>
#include "../../utlity/sort/cSortLib.h"
#include "../../utlity/Performance/PerformanceFunctions.h"


bool cSTLMap::add_person(const sPerson& person)
{
	return false;
}

bool cSTLMap::add_person(const std::string& key, const sPerson& person)
{
//	people_[(key)] = person;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	people_.insert(std::pair<std::string, sPerson>(key, person));

	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	return true;
}

bool cSTLMap::find_person_by_id(sPerson::id_type unique_id, sPerson& result_person)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::map<std::string,iPersonContainer::sPerson>::iterator it;
	
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = (*it).second;
		if (unique_id == itPeople.unique_id)
		{
			result_person = itPeople;
			flag = 1;
		}
	}

	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLMap::empty()
{
	if (people_.empty())
		return true;
	else
		return false;
}

iPersonContainer::sPerson::size_type cSTLMap::size()
{
	return people_.size();
}

bool cSTLMap::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::map<std::string,iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = (*it).second;
		if (max_number_of_results > result_people.size())
			if (person_to_match.first.empty() && person_to_match.last.empty())
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
			else if (person_to_match.first == itPeople.first && person_to_match.last.empty())
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
			else if (person_to_match.last == itPeople.last && person_to_match.first.empty())
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
			else if (person_to_match.first == itPeople.first && person_to_match.last == itPeople.last)
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
	}

	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLMap::find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::map<std::string,iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
	iPersonContainer::sPerson itPeople = (*it).second;
		if (max_number_of_results > result_people.size())
			if (itPeople.health >= min_health && itPeople.health <= max_health)
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
	}
	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLMap::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::map<std::string,iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = (*it).second;
		if (max_number_of_results > result_people.size())
		{
			float dx = location.x - itPeople.location.x;
			float dy = location.y - itPeople.location.y;
			float dz = location.z - itPeople.location.z;
			float mul = (dx * dx) + (dy * dy) + (dz * dz);
			float tobecheckedwithradius = sqrt(mul);

			if (radius >= tobecheckedwithradius)
			{
				result_people.push_back(itPeople);
				flag = 1;
			}

		}
	}
	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLMap::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::map<std::string,iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = (*it).second;
		if (max_number_of_results > result_people.size())
		{
			float dx = location.x - itPeople.location.x;
			float dy = location.y - itPeople.location.y;
			float dz = location.z - itPeople.location.z;
			float mul = (dx * dx) + (dy * dy) + (dz * dz);
			float tobecheckedwithradius = sqrt(mul);

			if (radius >= tobecheckedwithradius && (itPeople.health >= min_health && itPeople.health <= max_health))
			{
				result_people.push_back(itPeople);
				flag = 1;
			}

		}
	}
	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLMap::get_last_call_performance(sPerformanceData& performance_data)
{
	performance_data = last_call_performance_;
	cPerformanceData cPD;
	auto flag = 0;
	flag = cPD.printPreformanceData(performance_data);
	if (flag = 1)
		return true;
	else
	{
		printf("There was an error getting performance data.\n");
		return false;
	}
}

bool cSTLMap::sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	auto flag = 0;
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	switch (sort_function)
	{
	case sort_function_type::asc_first_last:
	{
		std::map<std::string, sPerson> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(itPerson.first, itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::desc_first_last:
	{
		std::map<std::string, sPerson, std::greater<std::string>> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(itPerson.first, itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::asc_last_first:
	{
		std::map < std::string, sPerson > tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(itPerson.last, itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::desc_last_first:
	{
		std::map < std::string, sPerson, std::greater<std::string >> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(itPerson.last, itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::asc_id:
	{
		std::map<std::string, sPerson> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(std::to_string(itPerson.unique_id), itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::desc_id:
	{
		std::map<std::string, sPerson, std::greater<std::string>> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(std::to_string(itPerson.unique_id), itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::asc_health:
	{
		std::map<std::string, sPerson> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(std::to_string(itPerson.health), itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	case sort_function_type::desc_health:
	{
		std::map<std::string, sPerson, std::greater<std::string>> tempMap;
		for (std::map<std::string, sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			tempMap.insert(std::pair < std::string, sPerson>(std::to_string(itPerson.health), itPerson));
		}
		for (std::map<std::string, sPerson>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
		{
			iPersonContainer::sPerson itPerson = (*it).second;
			result_people.push_back(itPerson);
		}
		flag = 1;
		break;
	}
	default:
		flag = 0;
		break;
	}

	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;

	if (flag == 1)
		return true;
	else
		return false;
}
