#include "cSTLList.h"
#include<cmath>
#include <ctime>
#include <Windows.h>
#include <psapi.h>
#include<algorithm>
#include "../../utlity/sort/cSortLib.h"

bool cSTLList::add_person(const sPerson& person)
{
	people_.push_back(person);
	return true;
}

bool cSTLList::find_person_by_id(sPerson::id_type unique_id, sPerson& result_person)
{
	auto flag = 0;
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
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
		if (max_number_of_results >= result_people.size())
			if (person_to_match.first == itPeople.first)
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
	}
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLList::find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;
	std::list<iPersonContainer::sPerson>::iterator it;
	for (it = people_.begin(); it != people_.end(); it++)
	{
		iPersonContainer::sPerson itPeople = *it;
		if (max_number_of_results >= result_people.size())
			if (itPeople.health >= min_health && itPeople.health <= max_health)
			{
				result_people.push_back(itPeople);
				flag = 1;
			}
	}
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLList::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;
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
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLList::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;
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
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLList::get_last_call_performance(sPerformanceData& performance_data)
{
	auto const process = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS counter;
	const auto start_time = clock();

	if (process == nullptr) {
		return false;
	}

	if (GetProcessMemoryInfo(process, &counter, sizeof(counter))) {
		printf("%lu bytes in use\n", counter.WorkingSetSize);

		if (counter.WorkingSetSize < performance_data.memory_usage_bytes_min)
			performance_data.memory_usage_bytes_min = counter.WorkingSetSize;

		if (counter.WorkingSetSize > performance_data.memory_usage_bytes_max)
			performance_data.memory_usage_bytes_max = counter.WorkingSetSize;


		performance_data.memory_usage_bytes_avg = (performance_data.memory_usage_bytes_max
			+ performance_data.memory_usage_bytes_min) / 2;

		const auto end_time = clock();
		const auto ticks = static_cast<float>(end_time) - static_cast<float>(start_time);

		performance_data.elapsed_call_time_ms = ticks / CLOCKS_PER_SEC / 60;
		return true;
	}
	else
	{

		printf("There was an error getting performance data.\n");
		return false;
	}
}

bool cSTLList::sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people)
{

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
	
	return true;
}
