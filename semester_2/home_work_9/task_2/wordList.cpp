#include "wordList.h"
#include <iostream>
#include <string>

WordList::WordList() : head(nullptr), length(0)
{
}

WordList::~WordList()
{
    while (head != nullptr)
    {
        Node *removingNode = head;
        head = head->getNext();
        delete removingNode;
    }
}

void WordList::add(const std::string &word)
{
    if (head == nullptr)
    {
        head = new Node(word);
        ++length;
        return;
    }

    Node *currentNode = head;
    Node *previousNode = nullptr;
    while (currentNode != nullptr)
    {
        if (currentNode->getWord() == word)
            break;
        previousNode = currentNode;
        currentNode = currentNode->getNext();
    }
    if (currentNode == nullptr)
    {
        Node *newNode = new Node(word);
        previousNode->setNext(newNode);
        ++length;
    }
}

void WordList::remove(const std::string &word)
{
    if (head == nullptr)
        return;

    if (head->getWord() == word)
    {
        Node *removingNode = head;
        head = head->getNext();
        delete removingNode;
        --length;
        return;
    }

    Node *currentNode = head->getNext();
    Node *previousNode = head;
    while (currentNode != nullptr)
    {
        if (currentNode->getWord() == word)
        {
            previousNode->setNext(currentNode->getNext());
            delete currentNode;
            --length;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->getNext();
    }
}

int WordList::getLength() const
{
    return length;
}

bool WordList::isInList(const std::string &word) const
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        if (currentNode->getWord() == word)
            return true;
        currentNode = currentNode->getNext();
    }
    return false;
}

void WordList::print()
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        std::cout << currentNode->getWord() << ' ';
        currentNode = currentNode->getNext();
    }
    std::cout << std::endl;
}


WordList::Node::Node(const std::string &word) : word(word), next(nullptr)
{
}

const std::string &WordList::Node::getWord() const
{
    return word;
}

WordList::Node *WordList::Node::getNext() const
{
    return next;
}

void WordList::Node::setNext(WordList::Node *next)
{
    this->next = next;
}
