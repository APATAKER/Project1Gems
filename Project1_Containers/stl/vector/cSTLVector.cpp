#include "cSTLVector.h"
#include<cmath>
#include <ctime>
#include <Windows.h>
#include <psapi.h>
#include<algorithm>
#include "../../utlity/sort/cSortLib.h"


bool cSTLVector::add_person(const sPerson& person)
{
	people_.push_back(person);
	return true;
}

bool cSTLVector::find_person_by_id(const sPerson::id_type unique_id, sPerson& result_person)
{
	auto flag = 0;
	for (int i = 0; i < people_.size(); i++)
	{
		if (unique_id == people_[i].unique_id)
		{
			result_person = people_[i];
			flag = 1;
		}
	}
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
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLVector::find_people(sPerson::health_type min_health, sPerson::health_type max_health,
	std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
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
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLVector::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{
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
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLVector::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health,
	sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
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
	if (flag == 1)
		return true;
	else
		return false;
}

bool cSTLVector::get_last_call_performance(sPerformanceData& performance_data)
{
	auto const process = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS counter;
	const auto start_time = clock();

	if (process == nullptr) {
		return false;
	}

	if (GetProcessMemoryInfo(process, &counter, sizeof(counter))) {
		//printf("%lu bytes in use\n", counter.WorkingSetSize);

		if(counter.WorkingSetSize < performance_data.memory_usage_bytes_min)
		performance_data.memory_usage_bytes_min = counter.WorkingSetSize;

		if(counter.WorkingSetSize > performance_data.memory_usage_bytes_max)
		performance_data.memory_usage_bytes_max = counter.WorkingSetSize;


		performance_data.memory_usage_bytes_avg = (performance_data.memory_usage_bytes_max
													+ performance_data.memory_usage_bytes_min)/2;

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

bool cSTLVector::sort_people(const sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	result_people = people_;
	switch (sort_function)
	{
	case sort_function_type::asc_first_last:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscFirst);
		return true;
	case sort_function_type::desc_first_last:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescFirst);
		return true;
	case sort_function_type::asc_last_first:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscLast);
		return true;
	case sort_function_type::desc_last_first:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescLast);
		return true;
	case sort_function_type::asc_id:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscId);
		return true;
	case sort_function_type::desc_id:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescId);
		return true;
	case sort_function_type::asc_health:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByAscHp);
		return true;
	case sort_function_type::desc_health:
		std::sort(result_people.begin(), result_people.end(), cSortLib::sortByDescHp);
		return true;
	default:
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
