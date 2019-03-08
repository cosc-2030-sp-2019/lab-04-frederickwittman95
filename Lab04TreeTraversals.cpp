// For some reason this is needed on the computers in the Engineering Building's labs
#include "pch.h"
#include<iostream>
using namespace std;

struct Node {
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;

	// Define constructors, for ease of tree building in main()

	Node() {};
	Node(int val, Node * right, Node * left) {
		value = val;
		rightNode = right;
		leftNode = left;
	}
};

Node * searchNode(Node * root, int value) {
	Node * rightResult;
	Node * leftResult;
	if (root == NULL) {
		return NULL;
	}
	else if (root->value == value) {
		return root;
	}
	else {
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL) {
			return NULL;
		}
		else if (rightResult != NULL) {
			return rightResult;
		}
		else {
			return leftResult;
		}
	}
}

void insertLeft(Node * Parent, Node * nodeToInsert)
{
	Parent->leftNode = nodeToInsert;

}


void insertRight(Node * Parent, Node * nodeToInsert)
{
	Parent->rightNode = nodeToInsert;

}


int inOrderTraversal(Node * root) {
	if (root != NULL) {
		inOrderTraversal(root->leftNode);
		cout << root->value << endl;
		inOrderTraversal(root->rightNode);
	}
	return 0;
}

int postOrderTraversal(Node * root) {
	if (root != NULL)
	{
		postOrderTraversal(root->leftNode);
		postOrderTraversal(root->rightNode);
		cout << root->value << endl;
	}
	return 0;
}

int preOrderTraversal(Node * root) {
	if (root != NULL) {
		cout << root->value << endl;
		preOrderTraversal(root->leftNode);
		preOrderTraversal(root->rightNode);
	}
	return 0;
}



int main() {

	// Build the tree structure shown by the diagram in the lab files
	Node * BinaryTree = new Node;
	BinaryTree->value = 5;
	Node * tmp = new Node;
	tmp->value = 1;
	BinaryTree->rightNode = tmp;
	tmp = new Node;
	tmp->value = 4;
	BinaryTree->leftNode = tmp;

	// The nested constructors seem sloppy.  It's a little quicker, and works for this purpose, but in the future I will likely just explicitly define and link the nodes.
	tmp = searchNode(BinaryTree, 4);
	tmp->leftNode = new Node(10, NULL, NULL);
	tmp->rightNode = new Node(15, NULL, new Node(8, NULL, NULL));

	tmp = searchNode(BinaryTree, 1);
	tmp->rightNode = new Node(7, new Node(9, NULL, NULL), NULL);
	
	// Tree structure complete.  Call the traversal functions
	cout << "Inorder traversal:" << endl;
	inOrderTraversal(BinaryTree);
	cout << endl;

	cout << "Preorder traversal:" << endl;
	preOrderTraversal(BinaryTree);
	cout << endl;
	
	cout << "Postorder traversal:" << endl;
	postOrderTraversal(BinaryTree);
	cout << endl;

	system("pause");
	return 0;
}

