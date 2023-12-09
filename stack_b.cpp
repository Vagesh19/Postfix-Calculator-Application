#include "stack_b.h"
#include <iostream>
#include <stdexcept>
using namespace std;
/* PART B */
/* Dynamic Stacks */

// Constructor
Stack_B::Stack_B()
{
    try
    {
        stk = new int[1024];
    }
    catch (...)
    {
        throw runtime_error("Out of Memory");
    }
    size = 0;
    capacity = 1024;
}

// Destructor
Stack_B::~Stack_B()
{
    delete stk;
    stk=nullptr;
}

void Stack_B::push(int data)
{
    if (size < capacity)
    {
        stk[size++] = data;
    }
    else
    {
        int *temp;
        try
        {
            temp = new int[capacity * 2];
        }
        catch (...)
        {
            throw runtime_error("Out of Memory");
        }
        for (int i = 0; i < size; i++)
        {
            temp[i] = stk[i];
        }
        delete stk;
        stk = temp;
        capacity *= 2;
        stk[size++] = data;
    }
}
int Stack_B::pop()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        if ((capacity / 2) >= 1024 && size <= (capacity / 4))
        {
            int *temp;
            try
            {
                temp = new int[capacity / 2];
            }
            catch (...)
            {
                throw runtime_error("Out of Memory");
            }
            for (int i = 0; i < size; i++)
            {
                temp[i] = stk[i];
            }
            delete[] stk; // Corrected memory deallocation
            stk = temp;
            capacity /= 2;
        }
        return stk[--size];
    }
}
int Stack_B::get_element_from_top(int idx)
{
    if (size - idx - 1 < 0)
    {
        throw runtime_error("Index out of range");
        return -1;
    }
    else
    {
        return stk[size - idx - 1];
    }
}

int Stack_B::get_element_from_bottom(int idx)
{
    if (idx > size - 1)
    {
        throw runtime_error("Index out of range");
        return -1;
    }
    else
    {
        return stk[idx];
    }
}

void Stack_B::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == 1)
    {
        for (int i = this->size - 1; i >= 0; i--)
        {
            cout << stk[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i <= this->size - 1; i++)
        {
            cout << stk[i] << endl;
        }
    }
}

int Stack_B::add()
{
    if(size>=2){
        int a = this->pop();
        int b = this->pop();
        this->push(a + b);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_B::subtract()
{
    if(size>=2){
        int a = this->pop();
        int b = this->pop();
        this->push(b-a);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_B::multiply()
{
    if(size>=2){
        int a = this->pop();
        int b = this->pop();
        this->push(a * b);
        return get_element_from_top(0);
    }
    else{
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
}

int Stack_B::divide()
{   
    if(size>=2){
        int a, b;
        a = this->pop();
        b = this->pop();
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

int *Stack_B::get_stack() // Get a pointer to the array
{
    return this->stk;
}

int Stack_B::get_size() // Get the size of the stack
{
    return this->size;
}
