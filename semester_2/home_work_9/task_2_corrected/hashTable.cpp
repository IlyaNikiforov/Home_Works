#include "hashTable.h"
#include "wordList.h"
#include <iostream>
#include <string>

HashTable::HashTable(HashFunction *hash, int size) : hash(hash), size(size)
{
    table = new WordList[size];
}

HashTable::~HashTable()
{
    delete[] table;
}

void HashTable::add(const std::string &word)
{
    int value = (*hash)(word, size);
    table[value].add(word);
}

void HashTable::remove(const std::string &word)
{
    int value = (*hash)(word, size);
    table[value].remove(word);
}

void HashTable::showStatistics() const
{
    int numberOfWords = 0;
    std::cout << "Распределение слов по ячейкам: ";
    for (int i = 0; i < size; ++i)
    {
        int length = table[i].getLength();
        std::cout << length << ' ';
        numberOfWords += length;
    }
    std::cout << std::endl;
    std::cout << "Коэффициент заполнения: " << static_cast<double>(numberOfWords) / size << std::endl;
}

bool HashTable::isInTable(const std::string &word) const
{
    int value = (*hash)(word, size);
    return table[value].isInList(word);
}

void HashTable::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << i << ' ';
        table[i].print();
    }
}
