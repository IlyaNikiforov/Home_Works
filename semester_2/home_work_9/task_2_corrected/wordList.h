#pragma once

#include <string>

/**
 * @brief A linked list of strings class
 */
class WordList
{
public:
    /**
     * @brief Create an empty linked list
     */
    WordList();

    /**
     * @brief Delete the linked list
     */
    ~WordList();

    /**
     * @brief Add a string into the linked list
     * @param word A string to add
     */
    void add(const std::string &word);

    /**
     * @brief Remove a string from the linked list
     * @param word A string to remove
     */
    void remove(const std::string &word);

    /**
     * @brief Get a length of the linked list
     * @return A length of the linked list
     */
    int getLength() const;

    /**
     * @brief Check if a string is in the linked list
     * @param word A string to check
     * @return True if a string has been found and false otherwise
     */
    bool isInList(const std::string &word) const;

    /**
     * @brief Print the linked list
     */
    void print();
private:
    class Node
    {
    public:
        Node(const std::string &word);
        const std::string &getWord() const;
        Node *getNext() const;
        void setNext(Node *next);
    private:
        std::string word;
        Node *next;
    };
    Node *head;
    int length;
};
