#include "cDIYVector.h"

bool cDIYVector::add_person(const sPerson& person)
{
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

	return true;
}

bool cDIYVector::find_person_by_id(const sPerson::id_type unique_id, sPerson& result_person)
{
	return false;
}

bool cDIYVector::empty()
{
	return false;
}

iPersonContainer::sPerson::size_type cDIYVector::size()
{
	return size_;
}

bool cDIYVector::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYVector::find_people(sPerson::health_type min_health, sPerson::health_type max_health,
	std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYVector::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people,
	sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYVector::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health,
	sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYVector::get_last_call_performance(sPerformanceData& performance_data)
{
	return false;
}

bool cDIYVector::sort_people(const sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	return false;
}