#include<iostream>
using namespace std;

class Node
{
	public:
	int data, height;
	Node *left, *right;

	Node(int value)
	{
		data = value;
		height = 1;
		left = right = NULL;
	}
};

// Calculation of Height
int getheight(Node *root)
{
	if(!root)
	return 0;

	return root->height;
}

// Calculation of Balance
int getBalance(Node *root)
{
	return getheight(root->left) - getheight(root->right);
}


// Left Rotation
Node* leftRotation(Node *root)
{
	Node *child = root->right;
	Node *childLeft = child->left;

	child->left = root;
	root->right = childLeft;

	// Update Height of Child and Root

	root->height = 1 + max(getheight(root->left), getheight(root->right));
	child->height = 1 + max(getheight(child->left), getheight(child->right));

	// return this operation to OG Node 
	return child;
}

// Right Rotation
Node* rightRotation(Node *root)
{
	Node *child = root->left;
	Node *childRight = child->right;

	child->right = root;
	root->left = childRight;

	// Update height of Child and Root

	root->height = 1 + max(getheight(root->left), getheight(root->right));
	child->height = 1 + max(getheight(child->left), getheight(child->right));

	// return this operation to OG Node 
	return child;
}


// Insertion Of New Nodesss
Node* insert(Node *root, int key)
{
	// If Root Doesnt Exist
	if(!root)
	return new Node(key);

	//If Root Exist
	// Left Insertion
	if(key < root->data)
	root->left = insert(root->left, key);

	//Right Insertion
	else if(key > root->data)
	root->right = insert(root->right, key);

	//If duplicate Value (Not Allowed)
	else
	return root;


	// Updation of height
	root->height = 1 + max(getheight(root->left), getheight(root->right));

	//Balancing Check
	int balance = getBalance(root);

	//CASES

	//Left Left Case
	if(balance > 1 && key < root->left->data)
	return rightRotation(root);

	//Right Right Case
	else if(balance < -1 && key > root->right->data)
	return leftRotation(root);

	//Left Right Case
	else if(balance > 1 && key > root->left->data)
	{
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}

	// Right Left Case
	else if(balance < -1 && key < root->right->data)
	{
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	//No Unbalancing
	else
	return root;

}

void inorder(Node *root)
{
	if(!root)
	return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	Node *root = NULL;

	//Duplicate elements are not allowed as its a BST
	root = insert(root,20);
	root = insert(root,10);
	root = insert(root,34);
	root = insert(root,55);
	root = insert(root,50);
	root = insert(root,46);
	root = insert(root,88);
	root = insert(root,90);
	root = insert(root,100);

	cout<<"In-Order Traversal: "<<endl;
	inorder(root);
}



// Overall ShortCut

// Created Class  
// Created int main(nodes)
// Created Insertion function 
// 		if else if and else condition
// 		height updation function 
// 		balancing check
// Created Height Updation
// Created Balance Updation
// Cases of Rotations
// Created Left Rot Function
// Created Right Rot Function