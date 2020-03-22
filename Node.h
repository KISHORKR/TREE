#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
#define INSERT_SUCCESS 1
#define INSERT_FAILED  0

#define PRE_ORDER      0
#define IN_ORDER       1
#define POST_ORDER     2

#define DELETE_SUCCESS 1
#define DELETE_FAILED  0


class Node
{

    private:
        int data;
        Node *right,*left;
    public:
        friend class BST;
        Node(int);
        ~Node();
        int add(int value);
        int delete_all();
        friend  void display(int,Node*);

    protected:
};

void display(int,Node*);

#endif // NODE_H
