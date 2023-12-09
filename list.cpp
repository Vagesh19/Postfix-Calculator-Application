#include "list.h"
#include "node.h"
#include <stdexcept>
using namespace std;
/* PART B */
/* Stacks using Linked Lists */

/*
Linked Lists with Sentinels
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/

List::List()
{
    try
    {
        sentinel_head = new Node(true);
        sentinel_tail = new Node(true);
    }
    catch (...)
    {
        throw runtime_error("Out of Memory");
    }
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
    size = 0;
}

List::~List()
{
    Node *temp = sentinel_head->next;
    while (!(temp->is_sentinel_node()))
    {
        Node *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    delete sentinel_head;
    delete temp;
}

// Insert an element at the tail of the linked list
void List::insert(int v)
{
    Node *temp = sentinel_head;
    while (!(temp->next->is_sentinel_node()))
    {
        temp = temp->next;
    }
    Node *ins;
    try
    {
        ins = new Node(v, sentinel_tail, temp);
    }
    catch (...)
    {
        throw runtime_error("Out of Memory");
    }
    sentinel_tail->prev = ins;
    temp->next = ins;
    size++;
}

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        Node *temp = sentinel_head;
        while (!((temp->next)->is_sentinel_node()))
        {
            temp = temp->next;
        }
        Node *pr = temp->prev;
        pr->next = sentinel_tail;
        Node *ne = temp->next;
        ne->prev = pr;
        int da = temp->get_value();
        delete temp;
        size--;
        return da;
    }
}

// Return the size of the linked list
// Do not count the sentinel elements
int List::get_size()
{
    return size;
}

// Return a pointer to the sentinel head of the linked list
Node *List::get_head()
{
    return sentinel_head;
}
