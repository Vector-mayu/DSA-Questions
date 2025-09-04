#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left, *right;

	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};

Node* Insert(Node *root, int target)
{
	if(!root) // Base Case
	{
		Node *temp = new Node(target);
		return temp;
	}

	if(target < root->data)
	{
		root->left = Insert(root->left, target);
	}
	else
	{
		root->right = Insert(root->right, target);
	}

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
  int arr[] = {23,45,66,34,78,90,41,52};
  Node *root = NULL;

  for(int i=0; i<8; i++)
  {
    root = Insert(root, arr[i]);
  }

  // Printing BST using Inorder Tree taversal
  inorder(root);

}