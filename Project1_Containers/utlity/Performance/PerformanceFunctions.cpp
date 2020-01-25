#include "PerformanceFunctions.h"

#include<iostream>
#include <iomanip>

void cPerformanceData::startPerformance(iPersonContainer::sPerformanceData* performance_data)
{
	
	float MemoryUsage = getMemoryUsage();
	if (MemoryUsage < performance_data->memory_usage_bytes_min)
		performance_data->memory_usage_bytes_min = MemoryUsage;

	if (MemoryUsage > performance_data->memory_usage_bytes_max)
		performance_data->memory_usage_bytes_max = MemoryUsage;


	performance_data->memory_usage_bytes_avg = (performance_data->memory_usage_bytes_max
			+ performance_data->memory_usage_bytes_min) / 2;
	
}

size_t cPerformanceData::getMemoryUsage()
{
	{
		auto const process = GetCurrentProcess();
		PROCESS_MEMORY_COUNTERS counter;
		GetProcessMemoryInfo(process, &counter, sizeof(counter));

		return counter.WorkingSetSize;
	}
}

void cPerformanceData::getStartTime()
{
	this->startTime = clock();
}

void cPerformanceData::getLasttime()
{
	this->endTime = clock();
}

void cPerformanceData::calcuCallTime(iPersonContainer::sPerformanceData* performance_data)
{
	if (startTime == 0.0f && endTime == 0.0f)
	{
		std::cout << "havn't called StartTime and EndTime" << std::endl;
	}
	const auto ticks = static_cast<float>(endTime) - static_cast<float>(startTime);
	performance_data->elapsed_call_time_ms = ticks / CLOCKS_PER_SEC;
}

bool cPerformanceData::printPreformanceData(iPersonContainer::sPerformanceData pd)
{
	//pd = last_call_performance_;
	if (pd.memory_usage_bytes_min != FLT_MAX)
	{
		std::cout << "Minimum memory usage :" << std::fixed << std::setprecision(2) << pd.memory_usage_bytes_min << std::endl;
		std::cout << "Maximum memory usage :" << std::fixed << std::setprecision(2) << pd.memory_usage_bytes_max << std::endl;
		std::cout << "Average memory usage :" << std::fixed << std::setprecision(2) << pd.memory_usage_bytes_avg << std::endl;
		std::cout << "Elapsed CallTime MS :" << pd.elapsed_call_time_ms << std::endl;
		return true;
	}
	else
	{

		printf("There was an error getting performance data.\n");
		return false;
	}
}
