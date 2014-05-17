#pragma once
#include "iostream"
#include "list.h"

using namespace std;

template <typename type>
class Set
{
	public:
		Set() : list(new List<type>) {}
		~Set()
		{
			delete list;
		}
		void add(type value)
		{
			list->add(value);
		}
		void del(type value)
		{
			list->del(value);
		}
		bool isExists(type value)
		{
			return list->isExists(value) >= 1;
		}
		///intersection of two Sets. Returns new Set
		static Set<type> *intersection(Set *list1, Set *list2);
		///unification of two Sets. Returns new Set
		static Set<type> *unification(Set *list1, Set *list2);
		/// functions for testing:
		int getSize()
		{
			return list->getSize();
		}
		type element(int i)
		{
			return list->element(i);
		}

	private:
		List<type> *list;
};

template <typename type>
Set<type> *Set <type> ::intersection(Set *set1, Set *set2)
{
	Set *set = new Set;
	int temp1 = 0;
	int temp2 = 0;
	int size = set1->list->getSize();
	for (int i = 0; i < size; i++)
	{
		temp1 = set1->list->isExists(set1->list->element(i));
		temp2 = set2->list->isExists(set1->list->element(i));
		if (temp2 > temp1)
			for (int j = 0; j < temp1; j++)
				set->add(set1->list->element(i));
		else
			for (int j = 0; j < temp2; j++)
				set->add(set1->list->element(i));
	}
	return set;
}

template <typename type>
Set<type>* Set<type>::unification(Set *set1, Set *set2)
{
	Set *set = new Set;
	int size = set2->list->getSize();
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < size; i++)
	{
		temp2 = set2->list->isExists(set2->list->element(i));
		for (int j = 0; j < temp2; j++)
			set->add(set2->list->element(i));
	}

	size = set1->list->getSize();

	for (int i = 0; i < size; i++)
	{
		temp1 = set1->list->isExists(set1->list->element(i));
		temp2 = set2->list->isExists(set1->list->element(i));
		if (temp1 > temp2)
			for (int j = 0; j < temp1 - temp2; j++)
				set->add(set1->list->element(i));
	}
	return set;
}
