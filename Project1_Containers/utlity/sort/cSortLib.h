#pragma once
#include<interfaces/iPersonContainer.h>
#include "../Project1_Containers/diy/list/cDIYList.h"

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


	// Different Sorting methods

	void swap(iPersonContainer::sPerson* a, iPersonContainer::sPerson* b);
	size_t partition(iPersonContainer::sPerson* s_person, int low, int high,
									const iPersonContainer::sort_function_type sort_function);
	struct sNode* partition(struct sNode* rootnode, struct sNode* lastnode, struct sNode** newHead, struct sNode** newEnd,
							iPersonContainer::sort_function_type sort_function);
	void merge(iPersonContainer::sPerson* s_person, int low, int middle, int high, const iPersonContainer::sort_function_type sort_function);
	
	void qSort(iPersonContainer::sPerson* s_person, int low, int high, //Quick sort
		   const iPersonContainer::sort_function_type sort_function);
	void bSort(iPersonContainer::sPerson* s_person, int size,			//Bubble sort
		const iPersonContainer::sort_function_type sort_function);
	void sSort(iPersonContainer::sPerson* s_person, int size,			//Selection sort
		const iPersonContainer::sort_function_type sort_function);
	void mSort(iPersonContainer::sPerson* s_person, int low, int high,	//Merge Sort
		const iPersonContainer::sort_function_type sort_function);

};
