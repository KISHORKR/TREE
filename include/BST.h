#ifndef BST_H
#define BST_H

#include "Node.h"

#define INSERT_SUCCESS 1
#define INSERT_FAILED  0

#define PRE_ORDER      0
#define IN_ORDER       1
#define POST_ORDER     2

#define DELETE_SUCCESS 1
#define DELETE_FAILED  0

#define DATA_PRESENT      1
#define DATA_NOT_PRESENT  0


class BST
{
    public:

         BST();

        virtual ~BST();

        /* Insert Element in BST */
        virtual int insert(int);

        /* Display all elements present in BST */
        void display();

        /* DFS Traversals */
        void preOrder();
        void inOrder();
        void postOrder();

        /* BFS Traversals */
        void BFS();

        /* Delete all elements present in BST */
        int delete_tree();

        /* Search a element present in BST */
        int search(int);

        /* remove a element present in BST */
        virtual int remove(int value);

    protected:
        Node *root;
    private:
        int insert(int,Node*);
        Node* remove(int value,Node* parent,Node* child);
        int search(int,Node*);
        int delete_tree(Node* parent);
        void display(int mode,Node *node);
        int min_value(Node* parent);
};

#endif // BST_H
