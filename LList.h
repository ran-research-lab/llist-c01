// class LList:
// Declaration of the ADT List using linked list
// Code from the OpenDSA book

#include "List.h"
#include <stdexcept>
#include <string>
#ifndef MAIN_LLIST_H
#define MAIN_LLIST_H

class Node {         // Singly linked list node class
public:
    ListItemType data;    // Value for this node
    Node *next;      // Point to next node in list

    // Constructor
    Node(ListItemType d = 0, Node *n = NULL) { data = d; next = n; }
};


class LList : public List {
private:
    Node *head;         // Pointer to list header
    Node *tail;         // Pointer to last element
    Node *curr;         // Access to current element
    int listSize;      // Size of list
public:

    LList() {
        // these are the buffer nodes
        tail = curr = new Node;
        head = new Node(0, tail);
    }
    // Destructor
    ~LList();

    // Remove all contents from the list, so it is once again empty
    void clear();

    // Insert "it" at the current location
    // The client must ensure that the list's capacity is not exceeded
    bool insert(const ListItemType& d);

    // Append "it" at the end of the list
    // The client must ensure that the list's capacity is not exceeded
    bool append(const ListItemType& it);

    // Remove and return the current element
    ListItemType remove();

    // Set the current position to the start of the list
    void moveToStart();

    // Set the current position to the end of the list
    void moveToEnd();

    // Move the current position one step left, no change if already at beginning
    void prev();

    // Move the current position one step right, no change if already at end
    void next();

    // Return the number of elements in the list
    int length() const;

    // Return the position of the current element
    int currPos() const;

    // Set the current position to "pos"
    bool moveToPos(int pos);

    // Return true if current position is at end of the list
    bool isAtEnd() const;

    // Return the current element
    ListItemType getValue() const;

    bool isEmpty() const;

    // Returns a string in the form < e0, e1 | e2 >, where the "|" indicates
    // the current position
    string to_string() const;

    // Overloading the assignment operator
    LList & operator=(const LList &other);

};


#endif //MAIN_LLIST_H
