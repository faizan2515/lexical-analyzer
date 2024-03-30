#include "Node.h"
#include <iostream>
Node::Node()
{
    next=NULL;
    object='/0';
}
void Node::setObject(char object)
{
    this->object=object;
}
char Node::getObject()
{
    return object;
}
void Node::setNext(Node* next)
{
    this->next=next;
}
Node* Node::getNext()
{
    return next;
}
