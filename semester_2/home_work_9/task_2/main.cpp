#include <iostream>
#include <string>
#include "hashTable.h"
#include "hashFunctions.h"
#include "hashTableTest.h"

/*
//код для интерактивного тестирования
//потерял смысл после добавления модульного тестирования
HashTable::HashFunction *hash[] = { &hash1, &hash2 };

void clearInput()
{
    while (std::cin.get() != '\n')
        ;
}
*/

int main()
{
    /*
    //код для интерактивного тестирования
    std::cout << "Тестирование хеш-таблицы" << std::endl;

    std::cout << "Введите номер хеш-функции (1 или 2): ";
    int functionNumber = 0;
    std::cin >> functionNumber;
    if (functionNumber != 1 && functionNumber != 2)
    {
        std::cout << "Недопустимый номер хеш-функции" << std::endl;
        return 0;
    }
    clearInput();

    HashTable table(hash[functionNumber - 1]);

    enum Operations
    {
        add = 1,
        remove = 2,
        search = 3,
        statistics = 4,
        print = 5,
        exit = 0
    };

    bool testingIsFinished = false;
    while (!testingIsFinished)
    {
        int operation = exit;
        std::cout << "Возможные действия:" << std::endl
                  << add << " - добавить слово" << std::endl
                  << remove << " - удалить слово" << std::endl
                  << search << " - поиск слова" << std::endl
                  << statistics << " - показать статистику использования" << std::endl
                  << print << " - вывести таблицу" << std::endl
                  << exit << " - выход" << std::endl;
        std::cout << "Введите номер операции: ";
        std::cin >> operation;

        clearInput();

        switch (operation)
        {
            case add:
            {
                std::cout << "Добавление слова" << std::endl;
                std::cout << "Введите слово: ";
                std::string word;
                std::getline(std::cin, word);
                table.add(word);
                std::cout << std::endl;
                break;
            }
            case remove:
            {
                std::cout << "Удаление слова" << std::endl;
                std::cout << "Введите слово: ";
                std::string word;
                std::getline(std::cin, word);
                table.remove(word);
                std::cout << std::endl;
                break;
            }
            case search:
            {
                std::cout << "Поиск слова" << std::endl;
                std::cout << "Введите слово: ";
                std::string word;
                std::getline(std::cin, word);
                if (table.isInTable(word))
                    std::cout << "Слово найдено" << std::endl;
                else
                    std::cout << "Слово не найдено" << std::endl;
                std::cout << std::endl;
                break;
            }
            case statistics:
            {
                std::cout << "Статистика использования" << std::endl;
                table.showStatistics();
                std::cout << std::endl;
                break;
            }
            case print:
            {
                std::cout << "Вывод содержимого таблицы" << std::endl;
                table.print();
                std::cout << std::endl;
                break;
            }
            case exit:
            {
                testingIsFinished = true;
                break;
            }
            default:
            {
                std::cout << "Нет такого действия" << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
    */
    HashTableTest test;
    QTest::qExec(&test);
}

