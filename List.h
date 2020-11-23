#pragma once
#include <iostream>

struct Node
{
    int _number; //!< data portion
    Node* _next; //!< pointer portion

    Node(int value)
    {
        _number = value;
        _next = 0;
    }
};

class List
{
public:
    // Default constructor
    List();
    
    // Destructor
    ~List();

    // Adds a node to the end of the list
    void AddToEnd(int value);

    // Adds a node to the front of the list
    void AddToFront(int value);

    // Returns the number of nodes in the list
    int Count() const;

    // Finds an item and returns the node that contains it
    // Only finds the first occurrence of value
    Node* FindItem(int value) const;

    // Inserts a new node in the correct position (sorted small to large)
    void Insert(int value);

    // Inserts a new node at the specified position
    void Insert(int value, int position);

    // Deletes a node with the specified value (first occurrence only)
    void Delete(int value);

    // Concatenates two lists
    void Concat(const List& Source);

    // Deletes all of the values in the list that are in Items
    void Delete(const List& Items);

    // Takes a sorted list and merges the items into the correct locations
    void Merge(List& rhs);

    // Displays the list
    friend std::ostream& operator<<(std::ostream& os, const List& rhs);

private:
    Node* getTail();
    Node* createNode(int32_t value);

private:
    Node* _head;  //!< Pointer to the front of the list

};