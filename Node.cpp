#include "Node.h"

Node::Node(int value):data(value),right(NULL),left(NULL)
{
    //ctor
}

Node::~Node()
{
    //dtor
}

int Node::add(int value){

   if(data == value)return INSERT_FAILED;
   else if(data > value)
   {
        if (left == NULL)
        {
            left = new Node(value);
            return INSERT_SUCCESS;
        }
        return left->add(value);
   }
   else
   {
       if (right == NULL)
       {
            right = new Node(value);
            return INSERT_SUCCESS;
       }
       return right->add(value);
   }

   return INSERT_FAILED;
}

void display(int mode,Node *node)
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

int Node::delete_all()
{
        if (left != NULL)
        {
            left->delete_all();
            delete left;
            left = NULL;
        }

        if (right != NULL)
        {
            right->delete_all();
            delete right;
            right =NULL;
        }

        return DELETE_SUCCESS;
}
