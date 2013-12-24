#pragma once

#include "list.h"
#include "strings.h"

List** hashCreate(int sizeOfHash);

int hashFunction(String *str, int sizeOfHash);

void hashAdd(String *str, List **list, int sizeOfHash);

bool hashExist(String *str, List **hashTable, int sizeOfHash);

void hashPrint(List** hashTable, int sizeOfHash);

void hashDelete(List** &hashTable, int sizeOfHash);

