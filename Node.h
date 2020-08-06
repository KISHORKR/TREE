#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <queue>
using namespace std;


class Node
{
    private:
        int data;
        Node *right,*left;

    public:

         Node(int);
        ~Node();

        friend class BST;
    protected:
};

void display(int,Node*);

#endif // NODE_H
