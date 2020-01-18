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
};
