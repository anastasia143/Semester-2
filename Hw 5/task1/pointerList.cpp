#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "pointerList.h"

using namespace std;

PointerList::PointerList()
{
    head = NULL;
    size = 0;
}

ListElement *createListElement(char* str, ListElement *pemp)
{
    ListElement *temp = new ListElement;
    temp->value = str;
    temp->next = pemp;
    return temp;
}

void PointerList::add(char *str)
{
    if (size == 0)
    {
        ListElement* temp = createListElement(str, NULL);
        head = temp;
    }
    else
    {
        ListElement* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        ListElement* pemp = createListElement(str, NULL);
        temp->next = pemp;
    }
    size++;
    return;
}

void PointerList::remove(char *str)
{
    if (size == 0)
        return;

    while (head->value == str)
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
        if (temp->next->value == str)
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

bool PointerList::checkAvailability(char *str)
{
    if (size == 0)
        return false;
    else
    {
        ListElement* temp = head;
        while(temp != NULL)
        {
            if (twoStringsComparison(temp->value, str))
                return true;
            temp = temp->next;
        }
    }
    return false;
}

void PointerList::print()
{
    if (size != 0)
    {
        ListElement* temp = head;
        while(temp != NULL)
        {
            cout << temp->value;
            temp = temp->next;
        }
    }
    return;
}

bool twoStringsComparison(char* str1, char* str2)
{
    if (strlen(str1) != strlen(str2))
        return false;
    int len = strlen(str1);
    for (int i = 0; i < len; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
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
