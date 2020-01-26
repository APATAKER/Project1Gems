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

void cSortLib::swap(iPersonContainer::sPerson* a, iPersonContainer::sPerson* b)
{
	iPersonContainer::sPerson *t = new iPersonContainer::sPerson();
	*t =*a;
	*a = *b;
	*b = *t;

	delete t;
}

size_t cSortLib::partition(iPersonContainer::sPerson* s_person, int low, int high, const iPersonContainer::sort_function_type sort_function)
{
	
	iPersonContainer::sPerson pivot = *(s_person+high);

	int i = low - 1;
	for(int j = low; j <= high-1; j++)
	{
		switch (sort_function)
		{
		case iPersonContainer::sort_function_type::asc_first_last:
			if (s_person[j].first == pivot.first)
			{
				if (s_person[j].last < pivot.last)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			}
			else
			if(s_person[j].first < pivot.first)
			{
				i++;
				swap(&s_person[i], &s_person[j]);
			}
			break;
		case iPersonContainer::sort_function_type::desc_first_last:
			if (s_person[j].first == pivot.first)
			{
				if (s_person[j].last > pivot.last)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			}
			else
				if (s_person[j].first > pivot.first)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			break;
		case iPersonContainer::sort_function_type::asc_last_first:
			if (s_person[j].last == pivot.last)
			{
				if (s_person[j].first < pivot.first)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			}
			else
				if (s_person[j].last < pivot.last)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			break;
		case iPersonContainer::sort_function_type::desc_last_first:
			if (s_person[j].last == pivot.last)
			{
				if (s_person[j].first > pivot.first)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			}
			else
				if (s_person[j].last > pivot.last)
				{
					i++;
					swap(&s_person[i], &s_person[j]);
				}
			break;
		case iPersonContainer::sort_function_type::asc_id:
			if(s_person[j].unique_id < pivot.unique_id)
			{
				i++;
				swap(&s_person[i], &s_person[j]);
			}
			break;
		case iPersonContainer::sort_function_type::desc_id:
			if (s_person[j].unique_id > pivot.unique_id)
			{
				i++;
				swap(&s_person[i], &s_person[j]);
			}
			break;
		case iPersonContainer::sort_function_type::asc_health:
			if (s_person[j].health < pivot.health)
			{
				i++;
				swap(&s_person[i], &s_person[j]);
			}
			break;
		case iPersonContainer::sort_function_type::desc_health:
			if (s_person[j].health > pivot.health)
			{
				i++;
				swap(&s_person[i], &s_person[j]);
			}
			break;
		}
	}
	swap(&s_person[i + 1], &s_person[high]);
	return i + 1;
}

void cSortLib::qSort(iPersonContainer::sPerson* s_person, int low, int high,const iPersonContainer::sort_function_type sort_function)
{
	if(low<high)
	{
		int pi = partition(s_person, low, high, sort_function);

		qSort(s_person, low, (pi - 1),sort_function);
		qSort(s_person, (pi + 1), high, sort_function);
	}
}

//asc_first_last,
//desc_first_last,
//asc_last_first,
//desc_last_first,
//asc_id,
//desc_id,
//asc_health,
//desc_health
