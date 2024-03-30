#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        void setObject(char object);
        char getObject();
        void setNext(Node* next);
        Node* getNext();

    private:
        char object;
        Node* next;
};

#endif // NODE_H
