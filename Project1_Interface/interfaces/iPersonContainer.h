#pragma once

#include <string>
#include <vector>

/**
 * \brief this is the interface for all your containers
 */
class iPersonContainer
{
public:
	//representation of a person in our containers
	struct sPerson
	{
		//simple representation of a point(position) in 3d space
		struct sPoint
		{
			sPoint() : x(0.0f), y(0.0f), z(0.0f) {}
			float x, y, z;
		};

		using id_type = unsigned int;
		using name_type = std::string;
		using age_type = unsigned int;
		using health_type = float;
		using location_type = sPoint;
		using size_type = size_t;

		id_type unique_id;
		name_type first;
		name_type last;
		age_type age;
		health_type health;
		location_type location;

		sPerson() : unique_id(0), age(0), health(0.0f) {}
	};

	/**
	 * \brief a list of available sort types for the person container
	 */
	using sort_function_type = enum class e_sort_types {
		asc_first_last,
		desc_first_last,
		asc_last_first,
		desc_last_first,
		asc_id,
		desc_id,
		asc_health,
		desc_health
	};

	virtual ~iPersonContainer() = default; //need a virtual destructor as we have pure virtual functions

	/**
	 * \brief checks if the container is empty
	 * \return true if there are no people in the container / false if there is at least one item in the container
	 */
	virtual bool empty() = 0;

	/**
	 * \brief get the number of items in the container
	 * \return the number of people in the container
	 */
	virtual sPerson::size_type size() = 0;
	
	/**
	 * \brief this function will add a sPerson object to the container
	 *		  the map does not use this function (just return false on map)
	 * \param person the person you want to add to the container
	 * \return true if successful / false if failure
	 */
	virtual bool add_person(const sPerson& person) = 0;

	/**
	 * \brief this function will add a sPerson object to the container
	 *		  this is for the map containers (not needed on vector or list..just return false)
	 * \param key a string representing a unique key for the sPerson 
	 * \param person the person you want to add to the container
	 * \return true if successful / false if failure
	 */
	virtual bool add_person(const std::string& key, const sPerson& person) = 0;

	/**
	 * \brief finds a person in the container with the specified unique id
	 * \param unique_id the unique identifier for the person you are looking for
	 * \param result_person the populated sPerson if found
	 * \return true if found in container / false if not in container
	 */
	virtual bool find_person_by_id(sPerson::id_type unique_id, sPerson& result_person) = 0;

	/**
	 * \brief find all people in container by first/last name (or both)
	 * \param person_to_match an sPerson with the first/last name we are looking for populated
	 * \param result_people a vector of sPeople results
	 * \param max_number_of_results maximum number of results
	 * \return true if there is at least one result / false if zero results
	 */
	virtual bool find_people(sPerson& person_to_match, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results) = 0;

	/**
	 * \brief find all people in container within a given radius around a given position
	 * \param location the center location for the search
	 * \param radius the radius of the search around the given point
	 * \param result_people a vector of sPeople results
	 * \param max_number_of_results maximum number of results
	 * \return true if there is at least one result / false if zero results
	 */
	virtual bool find_people(sPerson::location_type& location, float radius, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results) = 0;

	/**
	 * \brief find all people in container within a given health range (inclusive)
	 * \param min_health minimum health allowed
	 * \param max_health maximum health allowed
	 * \param result_people a vector of sPeople results
	 * \param max_number_of_results maximum number of results
	 * \return true if there is at least one result / false if zero results
	 */
	virtual bool find_people(sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results) = 0;

	/**
	 * \brief find all people in container within a given radius around a given position and within a given health range (inclusive)
	 * \param location the center location for the search
	 * \param radius the radius of the search around the given point
	 * \param min_health minimum health allowed
	 * \param max_health maximum health allowed
	 * \param result_people a vector of sPeople results
	 * \param max_number_of_results maximum number of results
	 * \return true if there is at least one result / false if zero results
	 */
	virtual bool find_people(sPerson::location_type& location, float radius, sPerson::health_type min_health, sPerson::health_type max_health, std::vector<sPerson>& result_people, sPerson::size_type max_number_of_results) = 0;

	/**
	 * \brief creates a sorted copy of the container
	 * \param result_people the sorted container
	 * \param sort_function the type of sort to be performed
	 * \return true on success / false on failure
	 */
	virtual bool sort_people(sort_function_type sort_function, std::vector<sPerson>& result_people) = 0;

	//represents memory and time usage for a given function call
	struct sPerformanceData
	{
		sPerformanceData() : elapsed_call_time_ms(0.0f), memory_usage_bytes_min(0.0f), memory_usage_bytes_max(0.0f), memory_usage_bytes_avg(0.0f) {}
		float elapsed_call_time_ms;
		float memory_usage_bytes_min;
		float memory_usage_bytes_max;
		float memory_usage_bytes_avg;
	};

	/**
	 * \brief gets the performance data from the last call
	 * \param performance_data the sPerformanceData to populate 
	 * \return true if there is performance data / false if no data is available
	 */
	virtual bool get_last_call_performance(sPerformanceData& performance_data) = 0;
};
