#include "Stack.h"
#include <iostream>
Stack::Stack()
{
    head=NULL;
}
void Stack::push(char object)
{
    Node* newNode= new Node();
    newNode->setObject(object);
    newNode->setNext(head);
    head=newNode;
}
char Stack::top()
{
    return head->getObject();
}
char Stack::pop()
{
        char c=head->getObject();
        Node* n=head;
        head=head->getNext();
        delete n;
        return c;
}
bool Stack::isEmpty()
{
    if(head==NULL)
        return true;
    return false;
}
