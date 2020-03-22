#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    BST mytree;
    int choice,val;
    while (true)
    {
        cout << "Please select the Operation" << endl;
        cout << "1.Insert Data" << endl << "2.Delete Tree" << endl << "3.Preorder Traversal (DFS)" << endl << "4.Inorder Traversal" << endl << "5.Postorder Traversal" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter Data : " ;
                cin >> val;
                if ( !mytree.insert(val)) cout << "Insertion Failed..." << endl;
                break;
            case 2:
                mytree.delete_tree();
                cout << "Tree Deleted..." << endl;
                break;
            case 3:
                mytree.preOrder();
                break;
            case 4:
                mytree.inOrder();
                break;
            case 5:
                mytree.postOrder();
                break;
            default:
                return 0;
        }
        cout << endl << endl;
    }

    return 0;
}
