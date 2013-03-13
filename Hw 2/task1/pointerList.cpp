#include <stdlib.h>
#include <iostream>
#include "pointerList.h"
using namespace std;


ListElement *createListElement(int value, ListElement *pemp)
{
    ListElement *temp = new ListElement;
    temp->value = value;
    temp->next = pemp;
    return temp;
}

PointerList::PointerList()
{
    head = NULL;
    size = 0;
}

void PointerList::add(int value)
{
    if (size == 0)
    {
        ListElement* temp = createListElement(value, NULL);
        head = temp;
    }
    else
    {
        ListElement* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        ListElement* pemp = createListElement(value, NULL);
        temp->next = pemp;
    }
    size++;
    return;
}

void PointerList::remove(int value)
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
        return;
    }

    while (head->value == value)
        {
            if (size != 1)
            {
                ListElement *pemp = head;
                head = head->next;
                delete pemp;
                size--;
            }
            else
            {
                ListElement *pemp = head;
                head = NULL;
                delete pemp;
                size = 0;
                return;
            }
        }

    ListElement* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == value)
        {
            ListElement *pemp = temp->next;
            temp->next = temp->next->next;
            delete pemp;
            size--;
        }
        else
        {
            temp = temp->next;
        }
    }
    return;
}

void PointerList::print()
{
    if (size == 0)
        cout << "List is empty";
    else
    {
        ListElement* temp = head;
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return;
}

bool PointerList::check(int value)
{
    if (size == 0)
        return false;
    else
    {
        ListElement* temp = head;
        while(temp != NULL)
        {
            if (temp->value == value)
                return true;
            temp = temp->next;
        }
    }
    return false;
}

PointerList::~PointerList()
{
    ListElement *temp = head;
        while(temp != NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
}
