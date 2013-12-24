#pragma once

struct StackElement
{
    char value;
    StackElement *next;
};

struct Stack
{
    StackElement *first;
};