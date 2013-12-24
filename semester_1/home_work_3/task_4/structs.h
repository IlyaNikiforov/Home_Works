#pragma once
struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    ListElement *first;
};
