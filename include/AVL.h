#ifndef AVL_H
#define AVL_H

#include "BST.h"


class AVL : public BST
{
    public:
        AVL();
        virtual ~AVL();
        AVL(const AVL& other);
        virtual int insert(int);
        virtual int remove(int);

    protected:

    private:
        Node* insert(int,Node*);
        Node* remove(int,Node*);
        Node* rightRotate(Node*);
        Node* leftRotate(Node*);
        int getBalance(Node*);
        int getHeight(Node*);
        Node* minNode(Node*);
};

#endif // AVL_H
