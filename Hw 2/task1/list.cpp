#include "list.h"
#include "pointerList.h"
#include "arrayList.h"

List* listCreator(int number)
{
    switch(number)
    {
    case 1:
    {
        List* list = new ArrayList();
        return list;
        break;
    }
    default:
    {
        List *list = new PointerList();
        return list;
        break;
    }
    }
}

