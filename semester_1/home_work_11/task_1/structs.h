#pragma once
struct ListElement
{
    double value;
	int degree;
    ListElement *next;
};

struct List
{
    ListElement *first;
};
