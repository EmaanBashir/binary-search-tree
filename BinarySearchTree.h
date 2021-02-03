//BinarySearchTree.h
#include <iostream>
#include <cstdlib>
using namespace std;

//class Binary Search Tree
class BinarySearchTree{

//private struct
private:

	//struct for tree node
	struct tree_node {
		tree_node* left;
		tree_node* right;
		int data;
		int count = 1;
	};
	tree_node* root;

//public methods
public:

	//constructor
	BinarySearchTree() {
		root = NULL;
	}

	//is Empty method
	bool isEmpty() const { 
		return root == NULL; 
	}

	//inorder traversal on root
	void print_inorder() {
		inorder(root);
		cout << endl;
	}

	//inorder traversal on a node
	void inorder(tree_node* node) {
		if (node != NULL) {
			inorder(node->left);
			for (int i = 0; i < node->count; i++) {
				cout << node->data << " ";
			}
			inorder(node->right);
		}
	}

	//preorder traversal on root
	void print_preorder() {
		preorder(root);
		cout << endl;
	}

	//preorder traversal on a node
	void preorder(tree_node* node) {
		if (node != NULL) {
			for (int i = 0; i < node->count; i++) {
				cout << node->data << " ";
			}
			preorder(node->left);
			preorder(node->right);
		}
	}

	//postorder traversal on root
	void print_postorder() {
		postorder(root);
		cout << endl;
	}

	//postorder traversal on a node
	void postorder(tree_node* node) {
		if (node != NULL) {
			postorder(node->left);
			postorder(node->right);
			for (int i = 0; i < node->count; i++) {
				cout << node->data << " ";
			}
		}
	}
	
	//insert data
	void insert(int data) {
		tree_node* temp = new tree_node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		tree_node* parent = root;
		if (parent == NULL){ 
			root = temp;
		}
		else {

			//search for a suitable parent for the new node
			while (1) {
				if (parent->data > data && parent->left != NULL) {
					parent = parent->left;
				}
				else if (parent->data < data && parent->right != NULL) {
					parent = parent->right;
				}
				else {
					break;
				}
			}

			//insertion
			if (parent->data > data) {
				parent->left = temp;
			}
			else if (parent->data < data) {
				parent->right = temp;
			}
			else {
				parent->count++; 
			}
		}
	}

	//remove a node with a specific data
	void remove(int data) {
		tree_node* temp = root;
		tree_node* parent = NULL;
		if (temp == NULL) {
			cout << "Data not found!" << endl;
		}
		else {

			//search for the node to delete
			while (1) {
				if (temp->data > data && temp->left != NULL) {
					parent = temp;
					temp = temp->left;
				}
				else if (temp->data < data && temp->right != NULL) {
					parent = temp;
					temp = temp->right;
				}
				else {
					break;
				}
			}
			if (temp->data == data) {

				//node with no chidren
				if (temp->left == NULL && temp->right == NULL) {
					if (parent != NULL) {
						if (parent->left == temp) {
							parent->left = NULL;
						}
						else {
							parent->right = NULL;
						}
					}else {
						if (temp->right == NULL) {
							root = temp->left; cout << "SDf";
						}
						else {
							root = temp->right;
						}
					}
				}
				//node with one child
				else if (temp->left == NULL || temp->right == NULL) {
					tree_node* child;
					if (temp->right == NULL) {
						child = temp->left;
					}
					else {
						child = temp->right;
					}
					if (parent != NULL) {
						if (parent->left == temp) {
							parent->left = child;
						}
						else {
							parent->right = child;
						}
					}
					else {
						if (temp->right == NULL) {
							root = temp->left; cout << "SDf";
						}
						else {
							root = temp-> right;
						}
					}
				}
				//node with two children
				else {
					tree_node* min = getMin(temp->right);
					remove(min->data);
					temp->data = min->data;
					temp->count = min->count;
				}
			}
			else {
				cout << "Data not found!" << endl;
			}
		}
	}

	//method to get the node with min value of data
	tree_node* getMin(tree_node* node) {
		tree_node* temp = node;
		while (temp != NULL && temp->left != NULL) {
			temp = temp->left;
		}
		if (temp != NULL) {
			return temp;
		}
		else {
			cout << "Empty tree!" << endl;
			return 0;
		}
	}
};
