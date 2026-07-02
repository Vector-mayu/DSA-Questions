#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *left, *right;

	Node(int val){
		data = val;
		left = right = NULL;
	}
}

void preorder(Node *root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	int x;
	cout<<"Enter Root Node : ";
	cin>>x;

	Node *root = new Node(x);
	queue<Node*>q;
	q.push(root);

	int leftVal, rightVal;

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();

		cout<<"Enter Left Node of "<<temp->data<<": ";
		cin>>leftVal;
		if(leftVal != 0){
			temp->left = new Node(leftVal);
			q.push(temp->left);
		}

		cout<<"Enter Right Node of "<<temp->data<<": ";
		cin>>rightVal;
		if(rightVal != 0){
			temp->right = new Node(rightVal);
			q.push(temp->right);
		}
	}

	// lets implement preorder
	preorder(root);

	return 0;
}