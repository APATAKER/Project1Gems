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
	
	auto t =*a;
	*a = *b;
	*b = t;

	
}

void cSortLib::swap(cDIYList::sNode* a, cDIYList::sNode* b)
{
	iPersonContainer::sPerson temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void cSortLib::swap(cDIYMap::sHNode* a, cDIYMap::sHNode* b)
{
	iPersonContainer::sPerson temp = a->data;
	a->data = b->data;
	b->data = temp;
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







void cSortLib::merge(iPersonContainer::sPerson* s_person, int low, int middle, int high, const iPersonContainer::sort_function_type sort_function)
{
	int i, j, k;
	int n1 = middle - low + 1;
	int n2 = high - middle;

	iPersonContainer::sPerson* L = new iPersonContainer::sPerson[n1];
	iPersonContainer::sPerson* R = new iPersonContainer::sPerson[n2];

	for (i = 0; i < n1; i++)
		L[i] = s_person[low + i];
	for (j = 0; j < n2; j++)
		R[j] = s_person[middle + 1 + j];

	i = 0;
	j = 0;
	k = low;
	while(i < n1 && j < n2)
	{
		switch (sort_function)
		{
		case iPersonContainer::sort_function_type::asc_first_last:
			if (L[i].first == R[j].first)
			{
				if (L[i].last <= R[j].last)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			else
			{
				if (L[i].first <= R[j].first)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			break;
		case iPersonContainer::sort_function_type::desc_first_last:
			if (L[i].first == R[j].first)
			{
				if (L[i].last >= R[j].last)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			else
			{
				if (L[i].first >= R[j].first)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			break;
		case iPersonContainer::sort_function_type::asc_last_first:
			if (L[i].last == R[j].last)
			{
				if (L[i].first <= R[j].first)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			else
			{
				if (L[i].last <= R[j].last)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			break;
		case iPersonContainer::sort_function_type::desc_last_first:
			if (L[i].last == R[j].last)
			{
				if (L[i].first >= R[j].first)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			else
			{
				if (L[i].last >= R[j].last)
				{
					s_person[k] = L[i];
					i++;
				}
				else
				{
					s_person[k] = R[j];
					j++;
				}
				k++;
			}
			break;
		case iPersonContainer::sort_function_type::asc_id:
			if (L[i].unique_id <= R[i].unique_id)
			{
				s_person[k] = L[i];
				i++;
			}
			else
			{
				s_person[k] = R[j];
				j++;
			}
			k++;
			break;
		case iPersonContainer::sort_function_type::desc_id:
			if (L[i].unique_id >= R[i].unique_id)
			{
				s_person[k] = L[i];
				i++;
			}
			else
			{
				s_person[k] = R[j];
				j++;
			}
			k++;
			break;
		case iPersonContainer::sort_function_type::asc_health:
			if (L[i].health <= R[i].health)
			{
				s_person[k] = L[i];
				i++;
			}
			else
			{
				s_person[k] = R[j];
				j++;
			}
			k++;
			break;
		case iPersonContainer::sort_function_type::desc_health:
			if (L[i].health >= R[i].health)
			{
				s_person[k] = L[i];
				i++;
			}
			else
			{
				s_person[k] = R[j];
				j++;
			}
			k++;
			break;
		}
	}

	while(i<n1)
	{
		s_person[k] = L[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		s_person[k] = R[j];
		j++;
		k++;
	}
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

void cSortLib::bSort(iPersonContainer::sPerson* s_person, int size, const iPersonContainer::sort_function_type sort_function)
{
	int i, j;
	for(i=0;i<size-1;i++)
		for(j=0;j<size-i-1;j++)
		{
			switch (sort_function)
			{
			case iPersonContainer::sort_function_type::asc_first_last:
				if (s_person[j].first == s_person[j+1].first)
				{
					if (s_person[j].last < s_person[j+1].last)
					{	
						swap(&s_person[j], &s_person[j+1]);
					}
				}
				else
					if (s_person[j].first < s_person[j + 1].first)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				break;
			case iPersonContainer::sort_function_type::desc_first_last:
				if (s_person[j].first == s_person[j + 1].first)
				{
					if (s_person[j].last > s_person[j + 1].last)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				}
				else
					if (s_person[j].first > s_person[j + 1].first)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				break;
			case iPersonContainer::sort_function_type::asc_last_first:
				if (s_person[j].last == s_person[j + 1].last)
				{
					if (s_person[j].first < s_person[j + 1].first)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				}
				else
					if (s_person[j].last < s_person[j + 1].last)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				break;
			case iPersonContainer::sort_function_type::desc_last_first:
				if (s_person[j].last == s_person[j + 1].last)
				{
					if (s_person[j].first > s_person[j + 1].first)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				}
				else
					if (s_person[j].last > s_person[j + 1].last)
					{
						swap(&s_person[j], &s_person[j+1]);
					}
				break;
			case iPersonContainer::sort_function_type::asc_id:
				if (s_person[j].unique_id < s_person[j + 1].unique_id)
				{
					swap(&s_person[j], &s_person[j+1]);
				}
				break;
			case iPersonContainer::sort_function_type::desc_id:
				if (s_person[j].unique_id > s_person[j + 1].unique_id)
				{
					swap(&s_person[j], &s_person[j+1]);
				}
				break;
			case iPersonContainer::sort_function_type::asc_health:
				if (s_person[j].health < s_person[j + 1].health)
				{
					swap(&s_person[j], &s_person[j+1]);
				}
				break;
			case iPersonContainer::sort_function_type::desc_health:
				if (s_person[j].health > s_person[j + 1].health)
				{
					swap(&s_person[j], &s_person[j+1]);
				}
				break;
			}
		}
}

void cSortLib::sSort(iPersonContainer::sPerson* s_person, int size, const iPersonContainer::sort_function_type sort_function)
{
	int i, j,min_i;
	for(i=0;i<size-1;i++)
	{
		min_i = i;
		for(j=i+1;j<size;j++)
		{
			switch (sort_function)
			{
			case iPersonContainer::sort_function_type::asc_first_last:
				if (s_person[j].first == s_person[min_i].first)
				{
					if (s_person[j].last < s_person[min_i].last)
					{
						min_i=j;
					}
				}
				else
					if (s_person[j].first < s_person[min_i].first)
					{
						min_i=j;
					}
				break;
			case iPersonContainer::sort_function_type::desc_first_last:
				if (s_person[j].first == s_person[min_i].first)
				{
					if (s_person[j].last > s_person[min_i].last)
					{
						min_i=j;
					}
				}
				else
					if (s_person[j].first > s_person[min_i].first)
					{
						min_i=j;
					}
				break;
			case iPersonContainer::sort_function_type::asc_last_first:
				if (s_person[j].last == s_person[min_i].last)
				{
					if (s_person[j].first < s_person[min_i].first)
					{
						min_i=j;
					}
				}
				else
					if (s_person[j].last < s_person[min_i].last)
					{
						min_i=j;
					}
				break;
			case iPersonContainer::sort_function_type::desc_last_first:
				if (s_person[j].last == s_person[min_i].last)
				{
					if (s_person[j].first > s_person[min_i].first)
					{
						min_i=j;
					}
				}
				else
					if (s_person[j].last > s_person[min_i].last)
					{
						min_i=j;
					}
				break;
			case iPersonContainer::sort_function_type::asc_id:
				if (s_person[j].unique_id < s_person[min_i].unique_id)
				{
					min_i=j;
				}
				break;
			case iPersonContainer::sort_function_type::desc_id:
				if (s_person[j].unique_id > s_person[min_i].unique_id)
				{
					min_i=j;
				}
				break;
			case iPersonContainer::sort_function_type::asc_health:
				if (s_person[j].health < s_person[min_i].health)
				{
					min_i=j;
				}
				break;
			case iPersonContainer::sort_function_type::desc_health:
				if (s_person[j].health > s_person[min_i].health)
				{
					min_i=j;
				}
				break;
			}
		}
		swap(&s_person[min_i], &s_person[i]);
	}
}

void cSortLib::mSort(iPersonContainer::sPerson* s_person, int low, int high, const iPersonContainer::sort_function_type sort_function)
{
	if(low<high)
	{
		int middle = low + (high - low) / 2;

		mSort(s_person, low, middle,sort_function);
		mSort(s_person, middle + 1, high, sort_function);

		merge(s_person, low, middle, high, sort_function);
	}
}



void cSortLib::bLinkedSort(cDIYList::sNode* root, const iPersonContainer::sort_function_type sort_function)
{
	int swaped, i;
	cDIYList::sNode* ptr1;
	cDIYList::sNode* lptr = NULL;

	if(root == NULL)
		return;
	
	do
	{
		swaped = 0;
		ptr1 = root;

		while (ptr1->next_node != lptr)
		{
			switch (sort_function)
			{
			case iPersonContainer::sort_function_type::asc_first_last:
				if (ptr1->data.first == ptr1->next_node->data.first)
				{
					if (ptr1->data.last > ptr1->next_node->data.last)
					{
						swap(ptr1, ptr1->next_node);
							swaped = 1;
					}
				}
				else if (ptr1->data.first > ptr1->next_node->data.first)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_first_last:
				if (ptr1->data.first == ptr1->next_node->data.first)
				{
					if (ptr1->data.last < ptr1->next_node->data.last)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.first < ptr1->next_node->data.first)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::asc_last_first:
				if (ptr1->data.last == ptr1->next_node->data.last)
				{
					if (ptr1->data.first > ptr1->next_node->data.first)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.last > ptr1->next_node->data.last)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_last_first:
				if (ptr1->data.last == ptr1->next_node->data.last)
				{
					if (ptr1->data.first < ptr1->next_node->data.first)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.last < ptr1->next_node->data.last)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::asc_id:
				if(ptr1->data.unique_id > ptr1->next_node->data.unique_id)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_id:
				if (ptr1->data.unique_id < ptr1->next_node->data.unique_id)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::asc_health:
				if (ptr1->data.health > ptr1->next_node->data.health)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_health:
				if (ptr1->data.health < ptr1->next_node->data.health)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			}
			ptr1 = ptr1->next_node;
		}
		lptr = ptr1;
	} while (swaped);
}

void cSortLib::bMapSort(cDIYMap::sHNode* root, const iPersonContainer::sort_function_type sort_function)
{
	int swaped, i;
	cDIYMap::sHNode* ptr1;
	cDIYMap::sHNode* lptr = nullptr;

	if (root == nullptr)
		return;
	do
	{
		swaped = 0;
		ptr1 = root;

		while (ptr1->next_node != lptr)
		{
			switch (sort_function)
			{
			case iPersonContainer::sort_function_type::asc_first_last:
				if (ptr1->data.first == ptr1->next_node->data.first)
				{
					if (ptr1->data.last > ptr1->next_node->data.last)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.first > ptr1->next_node->data.first)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_first_last:
				if (ptr1->data.first == ptr1->next_node->data.first)
				{
					if (ptr1->data.last < ptr1->next_node->data.last)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.first < ptr1->next_node->data.first)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::asc_last_first:
				if (ptr1->data.last == ptr1->next_node->data.last)
				{
					if (ptr1->data.first > ptr1->next_node->data.first)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.last > ptr1->next_node->data.last)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_last_first:
				if (ptr1->data.last == ptr1->next_node->data.last)
				{
					if (ptr1->data.first < ptr1->next_node->data.first)
					{
						swap(ptr1, ptr1->next_node);
						swaped = 1;
					}
				}
				else if (ptr1->data.last < ptr1->next_node->data.last)
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::asc_id:
				if (std::to_string(ptr1->data.unique_id) > std::to_string(ptr1->next_node->data.unique_id))
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_id:
				if (std::to_string(ptr1->data.unique_id) < std::to_string(ptr1->next_node->data.unique_id))
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::asc_health:
				if (std::to_string(ptr1->data.health) > std::to_string(ptr1->next_node->data.health))
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			case iPersonContainer::sort_function_type::desc_health:
				if (std::to_string(ptr1->data.health) < std::to_string(ptr1->next_node->data.health))
				{
					swap(ptr1, ptr1->next_node);
					swaped = 1;
				}
				break;
			}
			ptr1 = ptr1->next_node;
		}
		lptr = ptr1;
	} while (swaped);
}

//asc_first_last,
//desc_first_last,
//asc_last_first,
//desc_last_first,
//asc_id,
//desc_id,
//asc_health,
//desc_health
