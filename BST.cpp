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

int BST::remove(int value)
{
    Node* delete_node;
    if (root == NULL) return DELETE_FAILED;
    if (root->get_value() == value)
    {
        Node temp(0);
        temp.set_left(root);
        delete_node = root->remove(value,&temp);
        root = temp.get_left();
    }
    else
    {
        delete_node = root->remove(value,NULL);
    }

    if(delete_node != NULL)
    {
            delete delete_node;
            return DELETE_SUCCESS;
    }

    return DELETE_FAILED;
}

int BST::search(int value)
{
    if(root == NULL) return DATA_NOT_PRESENT;
    else return root->search(value);
}

void BST::BFS()
{
    if(root == NULL) cout << "Tree is Empty :-(" << endl;
    root->BFS();
    cout << endl;
    return;
}

