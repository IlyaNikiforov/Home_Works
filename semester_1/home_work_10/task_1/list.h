#pragma once
#include "structs.h"
#include "strings.h"

struct ListElement;


struct List;


ListElement* createListElement(char value, ListElement *next);


List* createList();


void addSortedElement(List *list, char element);


void addSortedElement(List *list, TreeNode *treeNode);


TreeNode* removeFirstElement (List *list);


void printList(List *list);


void removeList(List *list);
