#include "cSortLib.h"

bool cSortLib::sortByAscFirst(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	if (lhs.first == rhs.first)
		return lhs.last < rhs.last;
	return lhs.first < rhs.first;
}

bool cSortLib::sortByDescFirst(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	if (lhs.first == rhs.first)
		return lhs.last > rhs.last;
	return lhs.first > rhs.first;
}

bool cSortLib::sortByAscLast(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	if (lhs.last == rhs.last)
		return lhs.first < rhs.first;
	return lhs.last < rhs.last;
}

bool cSortLib::sortByDescLast(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	if (lhs.last == rhs.last)
		return lhs.first > rhs.first;
	return lhs.last > rhs.last;
}

bool cSortLib::sortByAscId(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	return lhs.unique_id < rhs.unique_id;
}

bool cSortLib::sortByDescId(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	return lhs.unique_id > rhs.unique_id;
}

bool cSortLib::sortByAscHp(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	return lhs.health < rhs.health;
}

bool cSortLib::sortByDescHp(const iPersonContainer::sPerson& lhs, const iPersonContainer::sPerson& rhs)
{
	return lhs.health > rhs.health;
}

//asc_first_last,
//desc_first_last,
//asc_last_first,
//desc_last_first,
//asc_id,
//desc_id,
//asc_health,
//desc_health
