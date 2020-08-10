#include "BST.h"

BST::BST():root(NULL)
{
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
    return insert(value,root);
}


int BST::insert(int value, Node* parent)
{
    if(parent->data == value)return INSERT_FAILED;
    else if(parent->data > value)
    {
         if(parent->left == NULL){
            parent->left = new Node(value);
            return INSERT_SUCCESS;
         }
         return insert(value,parent->left);
    }
    else
    {
        if(parent->right == NULL){
            parent->right = new Node(value);
            return INSERT_SUCCESS;
         }
        return insert(value,parent->right);
    }
   return INSERT_FAILED;
}

void BST::inOrder(){

    if(root == NULL)
    {
        cout <<"The Tree is Empty :-(" << endl;
        return;
    }
    display(IN_ORDER,root);
    cout << endl;
    return;
}

void BST::preOrder(){

    if(root == NULL)
    {
        cout <<"The Tree is Empty :-(" << endl;
        return;
    }
    display(PRE_ORDER,root);
    cout << endl;
    return;
}

void BST::postOrder(){

    if(root == NULL)
    {
        cout <<"The Tree is Empty :-(" << endl;
        return;
    }

    display(POST_ORDER,root);
    cout << endl;
    return;
}

void BST::BFS()
{
    queue<Node*> buffer;
    if(root == NULL) {
        cout << "Tree is Empty :-(" << endl;
        return;
    }
    buffer.push(root);
    do
    {
        cout << buffer.front()->data << "\t" ;
        if(buffer.front()->left != NULL)  buffer.push(buffer.front()->left);
        if(buffer.front()->right != NULL) buffer.push(buffer.front()->right);
        buffer.pop();
    }while(!buffer.empty());
    cout << endl;
    return;
}

void BST::display()
{
    inOrder();
}

void BST::display(int mode,Node *node)
{
    if (node == NULL)
        return;
    switch(mode)
    {
        case PRE_ORDER:
            cout << node->data << "\t" ;
            display(PRE_ORDER,node->left);
            display(PRE_ORDER,node->right);
            break;
        case IN_ORDER:
            display(IN_ORDER,node->left);
            cout << node->data << "\t" ;
            display(IN_ORDER,node->right);
            break;
        case POST_ORDER:
            display(POST_ORDER,node->left);
            display(POST_ORDER,node->right);
            cout << node->data << "\t" ;
            break;
        default:
            cout << "Incorrect Mode Specified :-( " << endl;
    }
}

int BST::delete_tree()
{
    if (root == NULL)
    {
        cout << "Tree is Empty :-(" << endl;
        return DELETE_FAILED;
    }
    delete_tree(root);
    delete root;
    root = NULL;
    return DELETE_SUCCESS;
}

int BST::delete_tree(Node* parent)
{
       if (parent->left != NULL)
        {
            delete_tree(parent->left);
            delete parent->left;
            parent->left = NULL;
        }

        if (parent->right != NULL)
        {
            delete_tree(parent->right);
            delete parent->right;
            parent->right =NULL;
        }

        return DELETE_SUCCESS;
}

int BST::remove(int value)
{
    Node* delete_node;
    if (root == NULL) return DELETE_FAILED;
    if (root->data == value)
    {
        Node temp(0);
        temp.left = root;
        delete_node = remove(value,&temp,root);
        root = temp.left;
    }
    else
    {
        delete_node = remove(value,NULL,root);
    }

    if(delete_node != NULL)
    {
            delete delete_node;
            return DELETE_SUCCESS;
    }

    return DELETE_FAILED;
}

Node* BST::remove(int value,Node* parent,Node* child)
{
    Node* left = child->left;
    Node* right = child->right;
    if(value < child->data)
    {
        if(left != NULL) return remove(value,child,left);
        return NULL;
    }
    else if (value > child->data)
    {
        if(right != NULL) return remove(value,child,right);
        return NULL;
    }
    else
    {
        if (left != NULL && right != NULL)
        {
            child->data = min_value(right);
            return remove(child->data,child,right);
        }
        else if (parent->left == child)
        {
            parent->left = (left != NULL)?left:right;
            return child;
        }
        else if (parent->right == child)
        {
            parent->right = (left != NULL)?left:right;
            return child;
        }
    }
    return NULL;
}

int BST::min_value(Node* parent)
{
        if (parent->left == NULL)
            return parent->data;
        else
            return min_value(parent->left);
}


int BST::search(int value)
{
    if(root == NULL) return DATA_NOT_PRESENT;
    else return search(value,root);
}

int BST::search(int value,Node* parent)
{
    if(value == parent->data) return DATA_PRESENT;
    else if (value < parent->data)
    {
        if (parent->left != NULL)
        return search(value,parent->left);
    }
    else
    {
        if (parent->right != NULL)
        {
            return search(value,parent->right);
        }
    }
    return DATA_NOT_PRESENT;
}

