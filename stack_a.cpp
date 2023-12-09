#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;
/* PART A */
/* Stacks using Fixed Size Arrays */

// Constructor
Stack_A ::Stack_A()
{
    this->size = 0;
}

void Stack_A::push(int data)
{
    if (this->size == 1024)
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[size++] = data;
    }
}

int Stack_A::pop()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
        return -1;
    }
    else
    {
        return (stk)[(--(size))];
    }
}

int Stack_A::get_element_from_top(int idx)
{
    if ((size - idx - 1) < 0)
    {
        throw runtime_error("Index out of range");
        return -1;
    }
    else
    {
        return (stk)[size - idx - 1];
    }
}

int Stack_A::get_element_from_bottom(int idx)
{
    if (idx > size - 1)
    {
        throw runtime_error("Index out of range");
        return -1;
    }
    else
    {
        return (stk)[idx];
    }
}

void Stack_A::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == 1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << stk[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i <= size - 1; i++)
        {
            cout << stk[i] << endl;
        }
    }
    cout << endl;
}

int Stack_A::add()
{   if(size>=2){
        int a = pop();
        int b = pop();
        push(a + b);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_A::subtract()
{
    
    if(size>=2){
        int a = pop();
        int b = pop();
        push(b - a);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_A::multiply()
{
    if(size>=2){
        int a = pop();
        int b = pop();
        push(a * b);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_A::divide()
{   
    if(size>=2){
        int a, b;
        a = pop();
        b = pop();
        if (b == 0)
        {
            throw runtime_error("Divide by Zero Error");
            return -1;
        }
        int c = b / a;
        if(abs(b)%abs(a)==0){
            push(c);
        }
        else if (b * a < 0)
        {
            push(c - 1);
        }
        else
        {
            push(c);
        }
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int *Stack_A::get_stack() // Get a pointer to the array
{
    return stk;
}

int Stack_A::get_size() // Get the size of the stack
{
    return size;
}
