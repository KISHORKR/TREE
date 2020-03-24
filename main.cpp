#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    BST mytree;
    int choice,val;
    while (true)
    {
        cout << "Please select the Operation" << endl;
        cout << "1.Insert Data" << endl << "2.Preorder Traversal" << endl << "3.Inorder Traversal (DFS)" << endl << "4.Postorder Traversal" << endl << "5.Search Data " << endl << "6.Delete Tree" <<endl << "7.Remove Data" << endl;
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
                mytree.preOrder();
                break;
            case 3:
                mytree.inOrder();
                break;
            case 4:
                mytree.postOrder();
                break;
            case 5:
                cout << "Enter the Data to Search : " ;
                cin >> val;
                if (!mytree.search(val))cout << "Data not found :-(" << endl;
                else cout << "Data found :-)" << endl;
                break;
            case 6:
                mytree.delete_tree();
                cout << "Tree Deleted..." << endl;
                break;
            case 7:
                cout << "Enter the data to remove :";
                cin >> val;
                if (!mytree.remove(val)) cout << "Data not found :-(" << endl;
                else cout << "Data Removed :-)" << endl;
                break;
            default:
                return 0;
        }
        cout << endl << endl;
    }

    return 0;
}
