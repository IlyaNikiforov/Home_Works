#pragma once

#include "wordList.h"
#include <string>

/**
 * @brief A hash table class
 */
class HashTable
{
public:
    /**
     * @brief Hash function
     * @param word A string to calculate hash value
     * @param hashSize A size of a hash table
     * @return Hash value for the string
     */
    typedef int HashFunction(const std::string &word, const int hashSize);

    /**
     * @brief Create an empty hash table
     * @param hash A pointer to a hash function
     * @param size A size of a hash table
     */
    HashTable(HashFunction *hash, const int size = 10);

    /**
     * @brief Delete the hash table
     */
    ~HashTable();

    /**
     * @brief Add a string into the hash table
     * @param word A string to add
     */
    void add(const std::string &word);

    /**
     * @brief Remove a string from the hash table
     * @param word A string to remove
     */
    void remove(const std::string &word);

    /**
     * @brief Show number of elements in the cells and load factor of the hash table
     */
    void showStatistics() const;

    /**
     * @brief Check if a string is in the hash table
     * @param word A string to check
     * @return True if a string has been found and false otherwise
     */
    bool isInTable(const std::string &word) const;

    /**
     * @brief Print the hash table
     */
    void print() const;
private:
    HashFunction *hash;
    const int size;
    WordList *table;
};

