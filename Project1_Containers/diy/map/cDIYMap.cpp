#include "cDIYMap.h"
#include "../../utlity/Performance/PerformanceFunctions.h"

bool cDIYMap::add_person(const sPerson& person)
{
	return false;
}

bool cDIYMap::add_person(const std::string& key, const sPerson& person)
{
	
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	if (empty())
	{
		root_node = new sHNode();
		last_node = root_node;
		last_node->data = person;
		last_node->key = key;

		size_++;
		flag = 1;
	}
	else
	{
		int dup = 0;
		sHNode* temp = root_node;
		while(temp)
		{
			if (temp->key == key)
			{
				dup = 1;
			}
		}
		if(dup != 1)
		{
			sHNode* new_node = new sHNode();
			new_node->data = person;
			new_node->key = key;

			last_node->next_node = new_node;

			last_node = new_node;

			size_++;
		}
		flag = 1;
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

bool cDIYMap::find_person_by_id(sPerson::id_type unique_id, sPerson& result_person)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	sHNode* temp = root_node;

	while (temp)
	{
		if (temp->data.unique_id == unique_id)
		{
			result_person = temp->data;
			flag = 1;
			if (flag == 1)
				break;
		}
		temp = temp->next_node;
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

bool cDIYMap::empty()
{
	if (!root_node)
		return 1;
	return 0;
}

iPersonContainer::sPerson::size_type cDIYMap::size()
{
	return size_;
}

bool cDIYMap::find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	sHNode* temp = root_node;

	while (temp)
	{
		if (max_number_of_results > result_people.size())
			if (person_to_match.first.empty() && person_to_match.last.empty())
			{
				result_people.push_back(temp->data);
				flag = 1;
			}
			else if (person_to_match.first == temp->data.first && person_to_match.last.empty())
			{
				result_people.push_back(temp->data);
				flag = 1;
			}
			else if (person_to_match.last == temp->data.last && person_to_match.first.empty())
			{
				result_people.push_back(temp->data);
				flag = 1;
			}
			else if (person_to_match.first == temp->data.first && person_to_match.last == temp->data.last)
			{
				result_people.push_back(temp->data);
				flag = 1;
			}
		temp = temp->next_node;
	}


	if (flag == 1)
		return true;
	else
		return false;
}

bool cDIYMap::find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	sHNode* temp = root_node;

	while (temp)
	{
		if (max_number_of_results > result_people.size())
			if (temp->data.health >= min_health && temp->data.health <= max_health)
			{
				result_people.push_back(temp->data);
				flag = 1;
			}
		temp = temp->next_node;
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

bool cDIYMap::find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	sHNode* temp = root_node;

	while (temp)
	{
		if (max_number_of_results > result_people.size())
		{
			float dx = location.x - temp->data.location.x;
			float dy = location.y - temp->data.location.y;
			float dz = location.z - temp->data.location.z;
			float mul = (dx * dx) + (dy * dy) + (dz * dz);
			float tobecheckedwithradius = sqrt(mul);

			if (radius >= tobecheckedwithradius)
			{
				result_people.push_back(temp->data);
				flag = 1;
			}

		}
		temp = temp->next_node;
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

bool cDIYMap::find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results)
{
	auto flag = 0;

	cPerformanceData PD;
	PD.getStartTime();
	PD.startPerformance(&PD.Cperformance_data);

	sHNode* temp = root_node;

	while (temp)
	{
		if (max_number_of_results > result_people.size())
		{
			float dx = location.x - temp->data.location.x;
			float dy = location.y - temp->data.location.y;
			float dz = location.z - temp->data.location.z;
			float mul = (dx * dx) + (dy * dy) + (dz * dz);
			float tobecheckedwithradius = sqrt(mul);

			if (radius >= tobecheckedwithradius && (temp->data.health >= min_health && temp->data.health <= max_health))
			{
				result_people.push_back(temp->data);
				flag = 1;
			}

		}
		temp = temp->next_node;
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

bool cDIYMap::get_last_call_performance(sPerformanceData& performance_data)
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

bool cDIYMap::sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people)
{
	return false;
}
