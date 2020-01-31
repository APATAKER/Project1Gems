#pragma once
#include <interfaces/iPersonContainer.h>

class cDIYMap : public iPersonContainer
{
	struct sHNode
	{
		sHNode() :next_node(nullptr) {}

		sHNode* next_node;
		sPerson data;
		std::string key;
		
	};

	sHNode* root_node;
	sHNode* last_node;
	size_t size_;
public:
	sPerformanceData last_call_performance_;

	bool add_person(const sPerson& person) override;
	bool add_person(const std::string& key, const sPerson& person) override;
	bool find_person_by_id(sPerson::id_type unique_id, sPerson& result_person) override;
	bool empty() override;
	sPerson::size_type size() override;
	bool find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results) override;
	bool find_people(sPerson::health_type min_health, sPerson::health_type max_health,
		std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results) override;
	bool find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people,
		sPerson::size_type max_number_of_results) override;
	bool find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health,
		sPerson::health_type max_health, std::vector<sPerson>& result_people,
		sPerson::size_type max_number_of_results) override;
	bool get_last_call_performance(sPerformanceData& performance_data) override;
	bool sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people) override;
	
};
