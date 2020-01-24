#include "PerformanceFunctions.h"

#include<iostream>

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
