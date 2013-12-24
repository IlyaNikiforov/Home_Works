# pragma once
#include "stdafx.h"
#include "structs.h"

struct ListElement;

struct List;

//void createList(List *list);

void addElement(List *list, int element);

void removeElement(List *list, int element);

void printList(List *list);