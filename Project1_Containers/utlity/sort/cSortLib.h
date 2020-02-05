#pragma once
#include<interfaces/iPersonContainer.h>
#include "../Project1_Containers/diy/list/cDIYList.h"
#include "../Project1_Containers/diy/map/cDIYMap.h"

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
template<typename  T>
	void Swap(T *a,T *b)
		{
			T t = *a;
			*a = *b;
			*b = t;
		}



	
	void swap(struct cDIYList::sNode* a, struct cDIYList::sNode* b);
	void swap(struct cDIYMap::sHNode* a, struct cDIYMap::sHNode* b);
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

	void bLinkedSort(struct cDIYList::sNode *root, const iPersonContainer::sort_function_type sort_function);

	void bMapSort(struct cDIYMap::sHNode* root, const iPersonContainer::sort_function_type sort_function);

};
