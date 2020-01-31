#include "cSTLList.h"
#include<cmath>
#include <ctime>
#include <Windows.h>
#include <psapi.h>
#include<algorithm>
#include "../../utlity/sort/cSortLib.h"
#include"../../utlity/Performance/PerformanceFunctions.h"

bool cSTLList::add_person(const sPerson& person)
{

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	people_.push_back(person);

	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	return true;
}

bool cSTLList::add_person(const std::string& key, const sPerson& person)
{
	return false;
}

bool cSTLList::find_person_by_id(sPerson::id_type unique_id, sPerson& result_person)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
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

bool cSTLList::empty()
{
	if (people_.empty())
		return true;
	else
		return false;
}

iPersonContainer::sPerson::size_type cSTLList::size()
{
	return people_.size();
}

bool cSTLList::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
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

bool cSTLList::find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
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

bool cSTLList::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
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

bool cSTLList::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
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

bool cSTLList::get_last_call_performance(sPerformanceData& performance_data)
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

bool cSTLList::sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people)
{

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	switch (sort_function)
	{
	case sort_function_type::asc_first_last:
		people_.sort(cSortLib::sortByAscFirst);
		break;
	case sort_function_type::desc_first_last:
		people_.sort(cSortLib::sortByDescFirst);
		break;
	case sort_function_type::asc_last_first:
		people_.sort(cSortLib::sortByAscLast);
		break;
	case sort_function_type::desc_last_first:
		people_.sort(cSortLib::sortByDescLast);
		break;
	case sort_function_type::asc_id:
		people_.sort(cSortLib::sortByAscId);
		break;
	case sort_function_type::desc_id:
		people_.sort(cSortLib::sortByDescId);
		break;
	case sort_function_type::asc_health:
		people_.sort(cSortLib::sortByAscHp);
		break;
	case sort_function_type::desc_health:
		people_.sort(cSortLib::sortByDescHp);
		break;
	default:
		break;
	}


	for (std::list<iPersonContainer::sPerson>::iterator it = people_.begin(); it != people_.end(); it++)
		result_people.push_back(*it);
	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;
	
	
	return true;
}
