#pragma once
#include "tree.h"
#include "strings.h"

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
