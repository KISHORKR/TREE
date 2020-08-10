
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <queue>

using namespace std;

class BST;
class AVL;

class Node
{
    private:
        int data,height;
        Node *right,*left;

    public:

        Node(int);
        virtual ~Node();

        friend class BST;
        friend class AVL;
    protected:
};


#endif // NODE_H
