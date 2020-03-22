#ifndef BST_H
#define BST_H
#include "Node.h"



class BST
{
    public:
        BST();
        ~BST();
        int insert(int);
        void display();
        void preOrder();
        void inOrder();
        void postOrder();
        int delete_tree();

    protected:

    private:
        Node *root;
};
#endif // BST_H
