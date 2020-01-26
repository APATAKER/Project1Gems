#include "cDIYVector.h"
#include "../../utlity/Performance/PerformanceFunctions.h"
#include "../../utlity/sort/cSortLib.h"
#include <algorithm>


cDIYVector::~cDIYVector()
{
	
}

bool cDIYVector::add_person(const sPerson& person)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	//first element
	if (capacity_ == 0)
	{
		people_ = new sPerson[1];
		capacity_ = 1;
	}
	//new element at capacity
	else if (size_ == capacity_)
	{
		auto* new_vector = new sPerson[capacity_ * 2];
		auto* write_ptr = new_vector;

		if (new_vector == nullptr) return false;

		auto iterator = people_;
		while (iterator != (people_ + size_))
		{
			/**write_ptr = *iterator;
			++write_ptr;
			++iterator;*/
			*write_ptr++ = *iterator++;
		}

		delete[] people_;
		people_ = new_vector;
		capacity_ *= 2;
	}

	//there is room in the container for another element
	*(people_ + size_++) = person;

	PD.startPerformance(&PD.Cperformance_data);
	PD.getLasttime();
	PD.calcuCallTime(&PD.Cperformance_data);
	last_call_performance_ = PD.Cperformance_data;

	return true;
}

bool cDIYVector::add_person(const std::string& key, const sPerson& person)
{
	return false;
}

bool cDIYVector::find_person_by_id(const sPerson::id_type unique_id, sPerson& result_person)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);
	
	for (int i = 0; i <= size_; i++)
	{
		sPerson itPerson= *(people_ + i);
		if (unique_id == itPerson.unique_id)
		{
			result_person = itPerson;
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

bool cDIYVector::empty()
{
	if (size_ == 0)
		return true;
	else
		return false;
}

iPersonContainer::sPerson::size_type cDIYVector::size()
{
	return (size_+1);
}

bool cDIYVector::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{

	auto flag = 0;
	
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	for (int i = 0; i < size_; i++)
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

bool cDIYVector::find_people(sPerson::health_type min_health, sPerson::health_type max_health,
	std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < size_; i++)
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

bool cDIYVector::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < size_; i++)
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

bool cDIYVector::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health,
	sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	auto flag = 0;
	for (int i = 0; i < size_; i++)
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

bool cDIYVector::get_last_call_performance(sPerformanceData& performance_data)
{
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

bool cDIYVector::sort_people(const sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	cSortLib slib;
	//result_people = people_;
	/*switch (sort_function)
	{
	case sort_function_type::asc_first_last:
		
		slib.qSort(people_, 0, size_, sort_function);
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
	}*/

	slib.qSort(people_, 0, size_, sort_function);

	for(int i=0;i<size_;i++)
	{
		result_people.push_back(people_[i]);
	}
	flag = 1;

	
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