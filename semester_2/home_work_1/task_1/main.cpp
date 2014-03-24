#include "linkedlist.h"
#include "arraylist.h"


int main()
{
    LinkedList *list = new LinkedList;
    list->addValue(7);
    list->addValue(3);
    list->addValue(11);
    list->print();
    list->deleteValue(3);
    list->deleteValue(4);
    list->print();
    delete list;


    ArrayList list2;
    list2.addValue(12);
    list2.addValue(2);
    list2.addValue(8);
    list2.print();
    list2.deleteValue(2);
    list2.deleteValue(5);
    list2.print();

    return 0;
}
