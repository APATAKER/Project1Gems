#pragma once
#include<interfaces/iPersonContainer.h>

class cSortLib {

public:
static bool sortByAscFirst(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByDescFirst(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByAscLast(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByDescLast(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByAscId(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByDescId(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByAscHp(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
static bool sortByDescHp(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs);
//static void pushToVecFromMap(const )


	//Quick Sort
void swap(iPersonContainer::sPerson* a, iPersonContainer::sPerson* b);

size_t partition(iPersonContainer::sPerson* s_person, int low, int high,
									const iPersonContainer::sort_function_type sort_function);
void qSort(iPersonContainer::sPerson* s_person, int low, int high,
		   const iPersonContainer::sort_function_type sort_function);

};
