#include "cSTLVector.h"
#include <iostream>
#include<cmath>
#include <ctime>
#include <Windows.h>
#include <psapi.h>
#include <iomanip>
#include <algorithm>
#include "../../utlity/sort/cSortLib.h"
#include"../../utlity/Performance/PerformanceFunctions.h"


bool cSTLVector::add_person(const sPerson& person)
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

bool cSTLVector::add_person(const std::string& key, const sPerson& person)
{
	return false;
}

bool cSTLVector::find_person_by_id(const sPerson::id_type unique_id, sPerson& result_person)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < people_.size(); i++)
	{
		if (unique_id == people_[i].unique_id)
		{
			result_person = people_[i];
			flag = 1;
		}
	}
	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;


	if(flag == 1)
		return true;
	else
		return false;


}

bool cSTLVector::empty()
{
	if (people_.empty())
		return true;
	else
		return false;
}

iPersonContainer::sPerson::size_type cSTLVector::size()
{
	return people_.size();
}

bool cSTLVector::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < people_.size(); i++)
	{
		if (max_number_of_results > result_people.size())
		{

			if (person_to_match.first.empty() && person_to_match.last.empty())
			{
				result_people.push_back(people_[i]);
				flag = 1;
			}
			else if (person_to_match.first == people_[i].first && person_to_match.last.empty())
			{
				result_people.push_back(people_[i]);
				flag = 1;
			}
			else if (person_to_match.last == people_[i].last && person_to_match.first.empty())
			{
				result_people.push_back(people_[i]);
				flag = 1;
			}
			else if (person_to_match.first == people_[i].first && person_to_match.last == people_[i].last)
			{
				result_people.push_back(people_[i]);
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

bool cSTLVector::find_people(sPerson::health_type min_health, sPerson::health_type max_health,
	std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < people_.size(); i++)
	{
		if (max_number_of_results > result_people.size())
			if (people_[i].health >= min_health && people_[i].health <= max_health)
			{
				result_people.push_back(people_[i]);
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

bool cSTLVector::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < people_.size(); i++)
	{
		if (max_number_of_results > result_people.size())
		{
			float dx = location.x - people_[i].location.x;
			float dy = location.y - people_[i].location.y;
			float dz = location.z - people_[i].location.z;
			float mul = (dx * dx) + (dy * dy) + (dz * dz);
			float tobecheckedwithradius = sqrt(mul);

			if (radius >= tobecheckedwithradius)
			{
				result_people.push_back(people_[i]);
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

bool cSTLVector::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health,
	sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < people_.size(); i++)
	{
		if (max_number_of_results > result_people.size())
		{
			float dx = location.x - people_[i].location.x;
			float dy = location.y - people_[i].location.y;
			float dz = location.z - people_[i].location.z;
			float mul = (dx * dx) + (dy * dy) + (dz * dz);
			float tobecheckedwithradius = sqrt(mul);

			if (radius >= tobecheckedwithradius && (people_[i].health >= min_health && people_[i].health <= max_health))
			{
				result_people.push_back(people_[i]);
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

bool cSTLVector::get_last_call_performance(sPerformanceData& performance_data)
{
	performance_data = last_call_performance_;
	if(performance_data.memory_usage_bytes_min != FLT_MAX)
	{
	std::cout << "Minimum memory usage :" <<std::fixed<< std::setprecision(2) << performance_data.memory_usage_bytes_min << std::endl;
	std::cout << "Maximum memory usage :" <<std::fixed<< std::setprecision(2)<< performance_data.memory_usage_bytes_max << std::endl;
	std::cout << "Average memory usage :" <<std::fixed<< std::setprecision(2)<< performance_data.memory_usage_bytes_avg << std::endl;
	std::cout << "Elapsed CallTime MS :" << performance_data.elapsed_call_time_ms << std::endl;
		return true;
	}
	else
	{

		printf("There was an error getting performance data.\n");
		return false;
	}
}

bool cSTLVector::sort_people(const sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);


	result_people = people_;
	switch (sort_function)
	{
	case sort_function_type::asc_first_last:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscFirst);
		flag = 1;
		break;
	case sort_function_type::desc_first_last:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescFirst);
		flag = 1;
		break;
	case sort_function_type::asc_last_first:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscLast);
		flag = 1;
		break;
	case sort_function_type::desc_last_first:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescLast);
		flag = 1;
		break;
	case sort_function_type::asc_id:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscId);
		flag = 1;
		break;
	case sort_function_type::desc_id:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescId);
		flag = 1;
		break;
	case sort_function_type::asc_health:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscHp);
		flag = 1;
		break;
	case sort_function_type::desc_health:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescHp);
		flag = 1;
		break;
	default:
		break;
	}
	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;

	if (flag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//asc_first_last,
//desc_first_last,
//asc_last_first,
//desc_last_first,
//asc_id,
//desc_id,
//asc_health,
//desc_health
