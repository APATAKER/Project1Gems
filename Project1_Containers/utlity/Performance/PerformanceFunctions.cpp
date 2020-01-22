#include "PerformanceFunctions.h"

#include<iostream>

void startPerformance(iPersonContainer::sPerformanceData& performance_data)
{
	
	float MemoryUsage = getMemoryUsage();
	if (MemoryUsage < performance_data.memory_usage_bytes_min)
		performance_data.memory_usage_bytes_min = MemoryUsage;

	if (MemoryUsage > performance_data.memory_usage_bytes_max)
		performance_data.memory_usage_bytes_max = MemoryUsage;


	performance_data.memory_usage_bytes_avg = (performance_data.memory_usage_bytes_max
			+ performance_data.memory_usage_bytes_min) / 2;
	
}

size_t getMemoryUsage()
{
	{
		auto const process = GetCurrentProcess();
		PROCESS_MEMORY_COUNTERS counter;
		GetProcessMemoryInfo(process, &counter, sizeof(counter));

		return counter.WorkingSetSize;
	}
}
