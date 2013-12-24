#pragma once

struct StackElement
{
    int value;
    StackElement *next;
};

struct Stack
{
    StackElement *first;
};