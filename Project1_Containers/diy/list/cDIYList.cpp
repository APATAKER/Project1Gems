#include "cDIYList.h"

bool cDIYList::add_person(const sPerson& person)
{
	if (empty())
	{
		root_node = new sNode();
		last_node = root_node;
		last_node->data = person;

		size_++;
		return true;
	}
	else
	{
		sNode* new_node = new sNode();
		new_node->data = person;

		last_node->next_node = new_node;

		last_node = new_node;

		size_++;
		return true;
	}

	return false;
}

bool cDIYList::add_person(const std::string& key, const sPerson& person)
{
	return false;
}

bool cDIYList::find_person_by_id(sPerson::id_type unique_id, sPerson& result_person)
{
	return false;
}

bool cDIYList::empty()
{
	return root_node == nullptr;
}

iPersonContainer::sPerson::size_type cDIYList::size()
{
	return size_;
}

bool cDIYList::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYList::find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYList::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYList::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYList::get_last_call_performance(sPerformanceData& performance_data)
{
	return false;
}

bool cDIYList::sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	return false;
}

