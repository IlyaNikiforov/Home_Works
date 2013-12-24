#pragma once
#include "stdafx.h"
#include "structs.h"

struct ListElement;


struct List;


void createListElement(ListElement *newElement, int value, ListElement *next);


void createList(List *list);


void addSortedElement(List *list, int element);


void addElement(List *list, int element);


void removeFirstElement (List *list);


void removeElement(List *list, int element);


void printList(List *list);


void removeList(List *list);
