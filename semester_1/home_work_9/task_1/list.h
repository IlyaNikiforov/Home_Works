#pragma once

#include "structs.h"
#include "string.h"

struct ListElement;


struct List;


ListElement* createListElement();


void addElement(List *list, String *element);


void printList(List *list);


void removeList(List *list);
