#include <iostream> // cout, endl
#include "List.h"

std::ostream& operator<<(std::ostream& os, const List& rhs)
{
    Node* list = rhs._head;
    while (list)
    {
        os << list->_number << "   ";
        list = list->_next;
    }

    return os;
}

List::List()
{
    _head = nullptr;
}

List::~List()
{
    Node* list = _head;
    while (list)
    {
        Node* tempNode = list;
        list = list->_next;
        delete tempNode;
    }
    _head = nullptr;
}

void List::AddToEnd(int value)
{
    Node* newNode = createNode(value);
    if (_head == nullptr)
    {
        AddToFront(value);
    }
    else
    {
        getTail()->_next = newNode;
    }
}

void List::AddToFront(int value)
{
    Node* newNode = createNode(value);
    if (_head == nullptr)
    {
        _head = newNode;
    }
    else
    {
        newNode->_next = _head;
        _head = newNode;
    }
}

int List::Count() const
{
    Node* list = _head;
    int32_t nodeCount = 0;
    while (list)
    {
        nodeCount++;
        list = list->_next;
    }
    return nodeCount;
}

Node* List::FindItem(int value) const
{
    Node* list = _head;
    while (list)
    {
        if (list->_number == value)
        {
            return list;
        }
        list = list->_next;
    }
    return nullptr;
}

void List::Insert(int value)
{
    Node* list = _head;
    if (_head == nullptr)
    {
        AddToFront(value);
        return;
    }

    Node* newNode = createNode(value);
    if (_head->_number >= value)
    {
        Node* tempNode = _head;
        _head = newNode;
        newNode->_next = tempNode;
        return;
    }

    while (list)
    {   
        if (!list->_next || list->_number <= value && list->_next->_number >= value) // reason it wont work is bc once it finds one less it inserts 
        {
            Node* tempNode = list->_next; 
            list->_next = newNode; 
            newNode->_next = tempNode;
            return;
        }
        else
        { 
            list = list->_next;
        }
    }
}

void List::Insert(int value, int position)
{
    Node* tempNode = _head;
    Node* switchNode = _head;
    Node* newNode = createNode(value);

    if (position >= Count() + 1)
    {
        return;
    }

    if (position == 0)
    {
        AddToFront(value);
    }
    else if (getTail()->_number == value)
    {
        for (int i = 0; i != position - 1; i++)
        {
            tempNode = tempNode->_next;
        }
        tempNode->_next = newNode;
        newNode->_next = getTail();
    }
    else
    {
        for (int i = 0; i != position; i++)
        {
            if (i != 0)
            {
                tempNode = tempNode->_next;
            }
            switchNode = switchNode->_next;
        }
        tempNode->_next = newNode;
        newNode->_next = switchNode;
    }

}

void List::Delete(int value)
{ // Only delete value once
    if (!_head)
    {
        return;
    }

    Node* list = _head;
    if (_head->_number == value)
    {
        if (!_head->_next)
        {
            delete list;
            _head = nullptr;
            return;
        }
        else
        {
            Node* deleteNode = _head;
            list = list->_next;
            delete deleteNode;
            _head = list;
            return;
        }
   }

   Node* checkNode = _head->_next;
   while (list->_next)
   {
       if (checkNode->_number == value)
       {
           list->_next = checkNode->_next;
           delete checkNode;
           return;
       }
       else
       {
           list = list->_next;
           checkNode = checkNode->_next;
       }

    }
    
}

void List::Concat(const List& Source)
{
    Node* list = Source._head;
    while (list)
    {
        AddToEnd(list->_number);
        list = list->_next;
    }
    
}

void List::Delete(const List& Items) 
{
    Node* deleteList = Items._head;
    Node* list = _head;
    if (!deleteList || !list)
    {
        return;
    }

    while (deleteList)
    {
        list = _head;
        while (list)
        {
            if (!list->_next)
            {
                break;
            }
            if (_head->_number == deleteList->_number)
            {
                while (_head->_number == deleteList->_number)
                {
                    if (_head->_next == nullptr)
                    {
                        delete _head;
                        _head = nullptr;
                    }
                    else
                    {
                        Node* deleteNode = _head;
                        list = list->_next;
                        delete deleteNode;
                        _head = list;
                    }
                }
            }
            else if (list->_next->_number == deleteList->_number)
            {
                Node* deleteNode = list->_next;
                list->_next = deleteNode->_next;
                delete deleteNode;
            }
            else
            {
                list = list->_next;
            }
        }
        deleteList = deleteList->_next;
    }
}

void List::Merge(List& rhs)
{
    Node* firstList = _head;
    Node* secondList = rhs._head;
    Node* deleteList = rhs._head;

    while (secondList)
    {
        firstList = _head;
        while (firstList)
        {
            if (rhs._head->_number <= _head->_number)
            {
                Node* newNode = createNode(rhs._head->_number);
                Node* tempNode = _head;
                newNode = _head;
                newNode->_next = tempNode;
                rhs._head = rhs._head->_next;
                break;
            }
            else if (!firstList->_next)
            {
                Node* newNode = createNode(secondList->_number);
                firstList->_next = newNode;
                break;
            }
            else if (firstList->_number <= secondList->_number && secondList->_number <= firstList->_next->_number)
            {
                Node* newNode = createNode(secondList->_number);
                Node* tempNode = firstList->_next;
                firstList->_next = newNode;
                newNode->_next = tempNode;
                break;
            }
            else if (firstList->_next->_number <= secondList->_number && secondList->_number <= firstList->_next->_number)
            {
                Node* newNode = createNode(secondList->_number);
                Node* tempNode = firstList->_next;
                firstList->_next = newNode;
                newNode->_next = tempNode;
                break;
            }
            firstList = firstList->_next;
        }
        secondList = secondList->_next;
    }
   
    while (deleteList)
    {
        Node* tempNode = deleteList->_next;
        rhs.Delete(deleteList->_number);
        deleteList = tempNode;
    }
}

Node* List::getTail()
{
    Node* tempNode = _head;
    while (tempNode->_next != nullptr)
    {
        tempNode = tempNode->_next;
    }
    return tempNode;
}

Node* List::createNode(int32_t value)
{
    return new Node(value);
}

//Node* List::MakeNode(int value) const
//{
   // return nullptr;
//}
