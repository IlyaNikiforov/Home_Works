#pragma once

#include "list.h"
#include "strings.h"

List** hashCreate(int sizeOfHash);

int hashFunction(String *str, int sizeOfHash);

void hashAdd(String *str, List **list, int sizeOfHash);

int hashMaxLength(List** hashTable, int sizeOfHash);

int hashWordAmount(List** hashTable, int sizeOfHash);

float hashLoadFactor(List** hashTable, int sizeOfHash);

int hashEmptyValues(List** hashTable, int sizeOfHash);

float hashMeanLength(List** hashTable, int sizeOfHash);

void hashPrint(List** hashTable, int sizeOfHash);

void hashDelete(List** &hashTable, int sizeOfHash);

