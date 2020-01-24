#pragma once
#include<interfaces/iPersonContainer.h>
#include <ctime>
#include <Windows.h>
#include <psapi.h>
#include<time.h>


class cPerformanceData
{
public:	
	cPerformanceData():startTime(0.0f),endTime(0.0f) {}
	void startPerformance(iPersonContainer::sPerformanceData* performance_data);
	size_t getMemoryUsage();
	
	float startTime;
	float endTime;
	void getStartTime();
	void getLasttime();
	void calcuCallTime(iPersonContainer::sPerformanceData* performance_data);
	iPersonContainer::sPerformanceData Cperformance_data;
};



