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
    while (list)
    {
        Node* newNode = createNode(value);
        if (list->_number > value)
        {
            list = list->_next;
        }
        else
        {
            Node* saveNode = list->_next;
            list->_next = newNode;
            newNode->_next = saveNode;
        }
    }
}

void List::Insert(int value, int position)
{
    Node* tempNode = _head;
    if (position == 0)
    {
        AddToFront(value);
    }
    else
    {
        for (int i = 0; i != position; i++)
        {
            if (i == position)
            {
                
            }
        }
    }

}

void List::Delete(int value)
{
    Node* list = _head;
    Node* deleteNode = _head->_next;
    while (list)
    {
        if (_head->_number == value)
        {
            list = _head->_next;
            delete _head;
            _head = list;
        }
        else if (deleteNode->_number == value) // Need to fix
        {
            list->_next = deleteNode->_next;
            delete deleteNode;
            continue;
        }
        list = list->_next;  
    }
}

void List::Concat(const List& Source)
{
}

void List::Delete(const List& Items)
{
   
}

void List::Merge(List& rhs)
{
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
