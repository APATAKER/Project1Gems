#pragma once
#include<interfaces/iPersonContainer.h>
#include <ctime>
#include <Windows.h>
#include <psapi.h>

void startPerformance(iPersonContainer::sPerformanceData& performance_data);

size_t getMemoryUsage();

