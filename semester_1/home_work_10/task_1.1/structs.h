#pragma once
#include "tree.h"

using namespace std;

struct ListElement
{
	TreeNode *value;
	ListElement *next;
};

struct List
{
	ListElement *first;
};
