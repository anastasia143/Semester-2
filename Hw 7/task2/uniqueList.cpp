#include <stdlib.h>
#include <iostream>
#include "uniqueList.h"
#include "uniqueExceptions.h"
using namespace std;

ListElement *createListElement(int value, ListElement *pemp)
{
    ListElement *temp = new ListElement;
    temp->value = value;
    temp->next = pemp;
    return temp;
}

UniqueList::UniqueList()
{
    head = NULL;
    size = 0;
}

void UniqueList::add(int value)
{
    if (size == 0)
    {
        ListElement* temp = createListElement(value, NULL);
        head = temp;
    }
    else
    {
        try
        {
            if (check(value))
                throw AddingExistingElement();

            ListElement* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            ListElement* pemp = createListElement(value, NULL);
            temp->next = pemp;
        }
        catch(AddingExistingElement &)
        {
            size--;
            cout << "This element has already added." << endl;
        }
    }
    size++;
    return;
}

void UniqueList::remove(int value)
{

    try
    {
        if (!check(value) || (size == 0))
            throw RemovingMissingElement();

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
    }
    catch(RemovingMissingElement &)
    {
        cout << "There is no this element in the list." << endl;
    }
    return;
}

void UniqueList::print()
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

bool UniqueList::check(int value)
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

void UniqueList::clear()
{
    ListElement *temp = head;
    while(temp != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    size = 0;
}

UniqueList::~UniqueList()
{
    clear();
}
