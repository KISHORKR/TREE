#include "BST.h"

BST::BST():root(NULL){
    //ctor
}

BST::~BST()
{
    //dtor
    delete_tree();
}




int BST::insert(int value)
{

    if(root == NULL)
    {
        root = new Node(value);
        return INSERT_SUCCESS;
    }
    return root->add(value);
}

void BST::inOrder(){

    if(root == NULL)
    {
        cout <<"The Tree is Empty :-(" << endl;
        return;
    }
    ::display(IN_ORDER,root);
    cout << endl;
    return;
}

void BST::preOrder(){

    if(root == NULL)
    {
        cout <<"The Tree is Empty :-(" << endl;
        return;
    }
    ::display(PRE_ORDER,root);
    cout << endl;
    return;
}

void BST::postOrder(){

    if(root == NULL)
    {
        cout <<"The Tree is Empty :-(" << endl;
        return;
    }
    ::display(POST_ORDER,root);
    cout << endl;
    return;
}

void BST::display()
{
    inOrder();
}


int BST::delete_tree()
{
    if (root == NULL)
    {
        cout << "Tree is Empty :-(" << endl;
        return DELETE_FAILED;
    }
    root->delete_all();
    delete root;
    root = NULL;
    return DELETE_SUCCESS;
}
