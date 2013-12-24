#pragma once
#include "structs.h"

struct ListElement;


struct List;


ListElement* createListElement(double value, int degree, ListElement *next);


List* createList();


void addSortedElement(List *list, double element, int degree);


void printList(List *list);


void removeList(List *list);
