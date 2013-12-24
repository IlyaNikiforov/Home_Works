#pragma once
#include "strings.h"

struct ListElement
{
    String *value;
	int count;
    ListElement *next;
};

struct List
{
    ListElement *first;
	int length;
};
