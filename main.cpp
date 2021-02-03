//Main.cpp
#include "BinarySearchTree.h"

int main()
{
	int option = 0;
	int data;
	BinarySearchTree bst;
	while (option != -1) {
		cout << "\n1)Insert new data\t2)Inorder Traversal\t3)Preorder Traversal\t4)Postorder Traversal\t5)Delete an item";
		cout << "\nEnter option number: ";
		cin >> option;
		cout << endl;
		switch (option) {
		case 1:
			int counter;
			cout << "Enter number of values to be inserted: ";
			cin >> counter;
			cout << "Enter data to be entered: ";
			for(int i = 0 ; i < counter ; i++){
				cin >> data;
				bst.insert(data);
			}
			cout << "Node(s) inserted"<<endl;
			break;
		case 2:
			bst.print_inorder();
			break;
		case 3:
			bst.print_preorder();
			break;
		case 4:
			bst.print_postorder();
			break;
		case 5:
			cout << "Enter data to be deleted: ";
			cin >> data;
			bst.remove(data);
			break;
		default:
			option = -1;
			break;
		}
	}
}
