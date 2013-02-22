#include <iostream>
#include <stdlib.h>
#include "listStack.h"
#include "stack.h"
using namespace std;

ListElement *createListElement(int value, ListElement *pemp)
{
    ListElement *temp = new ListElement;
    temp->value = value;
    temp->next = pemp;
    return temp;
}

ListStack::ListStack()
{
    head = NULL;
    size = 0;
}

ListStack::~ListStack()
{
    ListElement *temp = head;
    while(temp != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void ListStack::push(char value)
{
    ListElement *pemp = createListElement(value, NULL);
    if (size == 0)
        head = pemp;
    else
    {
        ListElement *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pemp;
    }
    size++;
}

void ListStack::pop()
{
    if (size == 0)
        cout << "Stack is empty";
    else if (size == 1)
    {
        ListElement *temp = head;
        head = NULL;
        delete temp;
        size--;
    }
    else
    {
        ListElement *temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        ListElement *pemp = temp->next;
        temp->next = NULL;
        delete pemp;
        size--;
    }

}

bool ListStack::empty()
{
    return (size == 0);
}

char ListStack::top()
{
    ListElement *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->value;
}
