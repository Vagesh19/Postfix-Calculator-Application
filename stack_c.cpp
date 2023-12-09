#include "stack_c.h"
#include "list.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Stack_C::Stack_C()
{
    try
    {
        stk = new List();
    }
    catch (...)
    {
        throw runtime_error("Out of Memory");
    }
}

// Destructor
Stack_C::~Stack_C()
{
    delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);
}

int Stack_C::pop()
{
    return stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx)
{
    Node *se = stk->get_head();
    if (stk->get_size() - idx <= 0)
    {
        throw runtime_error("Index out of range");
        return -1;
    }
    else
    {
        for (int i = 1; i <= stk->get_size() - idx; i++)
        {
            se = se->next;
        }
        return se->get_value();
    }
}

int Stack_C::get_element_from_bottom(int idx)
{
    Node *se = stk->get_head();
    if (stk->get_size() - idx <= 0)
    {
        throw runtime_error("Index out of range");
        return -1;
    }
    else
    {
        while (idx)
        {
            se = se->next;
            idx--;
        }
        return (se->next)->get_value();
    }
}

void Stack_C::print_stack(bool top_or_bottom)
{
    if (top_or_bottom)
    {
        Node *se = stk->get_head();
        while (!((se->next)->is_sentinel_node()))
        {
            se = se->next;
        }
        while (!(se->is_sentinel_node()))
        {
            cout << se->get_value() << endl;
            se = se->prev;
        }
    }
    else
    {
        Node *sh = (stk->get_head())->next;
        while (!(sh->is_sentinel_node()))
        {
            cout << sh->get_value() << endl;
            sh = sh->next;
        }
    }
}
int Stack_C::add()
{
    if(stk->get_size()>=2){
        int a = stk->delete_tail();
        int b = stk->delete_tail();
        this->push(a + b);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_C::subtract()
{
    
    if(stk->get_size()>=2){
        int a = stk->delete_tail();
        int b = stk->delete_tail();
        this->push(b-a);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_C::multiply()
{
    if(stk->get_size()>=2){
        int a = stk->delete_tail();
        int b = stk->delete_tail();
        this->push(a * b);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_C::divide()
{   
    if(stk->get_size()>=2){
        int a, b;
        a = stk->delete_tail();
        b = stk->delete_tail();
        if (b == 0)
        {
            throw runtime_error("Divide by Zero Error");
            return -1;
        }
        int c= b/a;
        if(abs(b)%abs(a)==0){
            push(c);
        }
        else if (b*a<0){
            push(c-1);
        }
        else{
            push(c);
        }
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

// Get a pointer to the linked list representing the stack
List *Stack_C::get_stack()
{
    return stk;
}

// Get the size of the stack
int Stack_C::get_size()
{
    return stk->get_size();
}
