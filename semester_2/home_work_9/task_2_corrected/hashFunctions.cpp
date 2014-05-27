#include <string>
#include "hashFunctions.h"

int hash1(const std::string &word, const int hashSize)
{
    int result = 0;
    int length = word.length();
    for (int i = 0; i < length; ++i)
        result = (result + static_cast<unsigned char>(word[i])) % hashSize;
    return result;
}

int hash2(const std::string &word, const int hashSize)
{
    int result = 0;
    int length = word.length();
    for (int i = 0; i < length; ++i)
        result = (static_cast<unsigned char>(word[i]) + (hashSize - 1) * result) % hashSize;
    return result;
}
