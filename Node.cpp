#include "Node.h"

Node::Node(int value):data(value),right(NULL),left(NULL)
{
    //ctor
}

Node::~Node()
{
    //dtor
}

int Node::min_value()
{
        if (left == NULL)
            return data;
        else
            return left->min_value();
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

int Node::search(int value)
{
    if(value == data) return DATA_PRESENT;
    else if (value < data)
    {
        if (left != NULL)
        return left->search(value);
    }
    else
    {
        if (right != NULL)
        {
            return right->search(value);
        }
    }
    return DATA_NOT_PRESENT;
}

int Node::get_value()
{
    return data;
}

void Node::set_left(Node* node)
{
    left = node;
}

Node* Node::get_left()
{
    return left;
}

Node* Node::remove(int value,Node* parent)
{
    if(value < data)
    {
        if(left != NULL) return left->remove(value,this);
        return NULL;
    }
    else if (value > data)
    {
        if(right != NULL) return right->remove(value,this);
        return NULL;
    }
    else
    {
        if (left != NULL && right != NULL)
        {
            data = right->min_value();
            return right->remove(data,this);
        }
        else if (parent->left == this)
        {
            parent->left = (left != NULL)?left:right;
            return this;
        }
        else if (parent->right == this)
        {
            parent->right = (left != NULL)?left:right;
            return this;
        }
    }
    return NULL;
}

void Node::BFS()
{
    queue<Node*> buffer;
    buffer.push(this);
    do
    {
        cout << buffer.front()->data << "\t" ;
        if(buffer.front()->left != NULL)  buffer.push(buffer.front()->left);
        if(buffer.front()->right != NULL) buffer.push(buffer.front()->right);
        buffer.pop();
    }while(!buffer.empty());

    return;
}
