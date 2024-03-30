#include "node.h"
#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        void push(char object);
        char top();
        char pop();
        bool isEmpty();

    private:
        Node* head;
};

#endif // STACK_H
