#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

void  inorder(BinaryTreeNode *root, vector<int>&ans){
	if(!root)
	return;

	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);

}

void makeMinHeap(BinaryTreeNode *root, vector<int>&ans, int &index){
	if(!root || index < 0)
	return;

	root->data = ans[index--];
	makeMinHeap(root->left, ans, index);
	makeMinHeap(root->right, ans, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int>ans;
	inorder(root, ans);

	int index = ans.size()-1;

	reverse(ans.begin(), ans.end());
	makeMinHeap(root, ans, index);

	return root;
}