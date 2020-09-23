//
// Created by Rafael Arce Nazario on 9/21/20.
//

#include "LList.h"


LList::~LList() { clear(); }

// Remove all elements
void LList::clear() {
    curr = head;
    while(curr->next != tail) remove();
    curr = tail;
}

// Insert d at current position
bool LList::insert(const ListItemType& d) {
    curr->next = new Node(curr->data, curr->next);
    curr->data = d;
    if (tail == curr) tail = curr->next;  // New tail
    listSize++;
    return true;
}

// Append d to list
bool LList::append(const ListItemType& d) {
    tail->next = new Node;
    tail->data = d;
    tail = tail->next;
    listSize++;
    return true;
}

// Remove and return current element
ListItemType LList::remove ()  {
    if (curr == tail) // Nothing to remove
        throw std::out_of_range("remove() in LList: current is at the tail, cannot remove");

    Node *tmp = curr->next;                 // Point to the node that will be deleted
    ListItemType tmpData = tmp->data;       // Remember value
    curr->data = curr->next->data;          // Pull forward the next element
    if (curr->next == tail) tail = curr;    // Removed last, move tail
    curr->next = curr->next->next;          // Point around unneeded link
    listSize--;                             // Decrement element count
    delete tmp;                             // Delete the node!
    return tmpData;                         // Return value
}

void LList::moveToStart()   { curr = head->next; } // Set curr at list start
void LList::moveToEnd()     { curr = tail; }          // Set curr at list end

// Move curr one step left; no change if now at front
void LList::prev() {
    if (head->next == curr) return; // No previous element
    Node *temp = head;
    // March down list until we find the previous element
    while (temp->next != curr) temp = temp->next;
    curr = temp;
}

// Move curr one step right; no change if now at end
void LList::next() { if (curr != tail) curr = curr->next; }

int LList::length() const { return listSize; } // Return list length


// Return the position of the current element
int LList::currPos() const {
    Node *temp = head->next;
    int i;
    for (i=0; curr != temp; i++)
        temp = temp->next;
    return i;
}

// Move down list to "pos" position
bool LList::moveToPos(int pos) {
    if ((pos < 0) || (pos > listSize)) return false;
    curr = head->next;
    for(int i=0; i<pos; i++) curr = curr->next;
    return true;
}

// Return true if current position is at end of the list
bool LList::isAtEnd() const { return curr == tail; }

// Return current element value.
ListItemType LList::getValue() const  {
        if (curr == tail) // No current element
            throw std::out_of_range("getvalue() in LList is currently at tail, which is not a a valid element");
        return curr->data;
}

// Check if the list is empty
bool LList::isEmpty() const { return listSize == 0; }


string LList::to_string() const {
    string res = "<";
    int i = 0;
    Node *tmp = head->next;
    while (tmp!=tail) {
        if ( tmp == curr) res += "|";
        res += std::to_string(tmp->data);
        if (tmp->next!= tail && curr != tmp->next)  res += ",";
        tmp = tmp->next;
    }
    if ( tmp == curr) res += "|";
    res += ">";
    return res;


}