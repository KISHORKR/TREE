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
        Node* insert(int,Node*);
        //virtual int remove(int);
        //virtual Node* remove(int,Node*);
        Node* rightRotate(Node*);
        Node* leftRotate(Node*);
        int getBalance(Node*);
        int getHeight(Node*);

    protected:

    private:
};

#endif // AVL_H
