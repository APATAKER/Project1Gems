#include "cDIYMap.h"

bool cDIYMap::add_person(const sPerson& person)
{
	return false;
}

bool cDIYMap::add_person(const std::string& key, const sPerson& person)
{
	
	return false;
}

bool cDIYMap::find_person_by_id(sPerson::id_type unique_id, sPerson& result_person)
{
	return false;
}

bool cDIYMap::empty()
{
	return false;
}

iPersonContainer::sPerson::size_type cDIYMap::size()
{
	return sPerson::size_type();
}

bool cDIYMap::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYMap::find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYMap::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYMap::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	return false;
}

bool cDIYMap::get_last_call_performance(sPerformanceData& performance_data)
{
	return false;
}

bool cDIYMap::sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	return false;
}
