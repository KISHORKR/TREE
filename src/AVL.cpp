#include "AVL.h"
#include<Exception>
AVL::AVL()
{
    //ctor
}

AVL::~AVL()
{
    //dtor
     delete_tree();
}

AVL::AVL(const AVL& other)
{
    //copy ctor
}



int AVL::getHeight(Node* node)
{
    if(node == NULL)
        return 0;
    return node->height;
}


int AVL::getBalance(Node* node)
{
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* AVL::rightRotate(Node* x)
{
    Node* y = x->left;
    Node* T1 = y->right;


    //Make required Rotation by changing pointers
    y->right = x;
    x->left = T1;

    //Update the Height of Changed Nodes
    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;

    //Return the new Root
    return y;
}


Node* AVL::leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T1 = y->left;


    //Make required Rotation by changing pointers
    y->left = x;
    x->right = T1;

    //Update the Height of Changed Nodes
    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;

    //Return the new root
    return y;
}




int AVL::insert(int value)
{
    if(root == NULL)
    {
        root = new Node(value);
        return INSERT_SUCCESS;
    }

    root = insert(value,root);
    return INSERT_SUCCESS;
}

Node* AVL::insert(int value,Node* node)
{
    //Step 1: Do the Normal BST insertion
    if(node == NULL)
    return (new Node(value));

    if(value < node->data)
    {
      node->left = insert(value,node->left);
    }
    else if(value > node->data)
    {
        node->right = insert(value,node->right);
    }

    //Step 2: Update the Height of Current Node after Insertion
    node->height = max(getHeight(node->left),getHeight(node->right)) + 1;


    //Step 3: Get the New Balance Factor after Insertion
    int balance = getBalance(node);

    //If Balance factor is greater than 1 then it will be Left Left or Left Right Case

    if(balance > 1 && value < node->left->data)
    {
        //Left Left Case...So perform Right Rotation.
        return rightRotate(node);
    }

    if(balance > 1 && value > node->left->data)
    {
        //Left Right Case...So perform Left Rotation followed by Right Rotation
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //If Balance factor is Less than -1 then it will be Right Right or Right Left Case

    if(balance < -1 && value > node->right->data)
    {
        //Right Right Case...So perform Right Rotation.
        return leftRotate(node);
    }

    if(balance < -1 && value < node->right->data)
    {
        //Right Left Case...So perform Left Rotation followed by Right Rotation
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //Return the Unchanged Pointer as it is balanced
    return node;
}




int AVL::remove(int value)
{
    if (root == NULL) return DELETE_FAILED;
    root = remove(value,root);
    return DELETE_SUCCESS;
}

Node* AVL::remove(int value,Node* node)
{
    //Step 1: Perform the Normal BST Delete.
    if(node == NULL)
    {
        return node;
    }

    if(value < node->data)
    {
        node->left = remove(value , node->left);
    }
    else if(value > node->data)
    {
        node->right = remove(value , node->right);
    }
    else
    {
        Node* temp;
        if(node->right == NULL || node->left == NULL)
        {
            temp = node->left ? node->left : node->right;

            if(temp == NULL)
            {
                //No child Case
                temp = node;
                node = NULL;
            }
            else
            {
                //Single Child Case
                *node = *temp;
            }
            delete temp;

        }
        else
        {
            //Two Child Case
            temp = minNode(node->right);
            node->data = temp->data;
            node->right = remove(node->data,node->right);

        }

    }

    //If the node is deleted then return
    if(node == NULL)
    {
        return node;
    }

    //Step 2: Update the height of the Current Node
    node->height = max(getHeight(node->left) , getHeight(node->right)) + 1;

    //Step 3: Get the Balance factor and check that the tree is unbalanced or not
    int balance = getBalance(node);

    //If the balance if greater than 1 then it will be Left Left or Left Right Case

    if(balance > 1 && getBalance(node->left) >= 0)
    {
        //Left Left Case
        return rightRotate(node);
    }

    if(balance > 1 && getBalance(node->left) < 0)
    {
        //Left Right Case
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //If the balance if Less than -1 then it will be Right Right or Right Left Case

    if(balance < -1 && getBalance(node->right) <= 0)
    {
        //Right Right Case
        return leftRotate(node);
    }

    if(balance < -1 && getBalance(node->right) > 0)
    {
        //Right Left Case
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


Node* AVL::minNode(Node* node)
{
    if(node->left == NULL) return node;
    else return minNode(node->left);
}
