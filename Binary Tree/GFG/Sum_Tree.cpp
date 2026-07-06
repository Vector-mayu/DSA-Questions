/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  
    bool computeSum(Node *root, int &sum){
        if(!root){
            sum = 0;
            return true;
        }
        
        if(!root->left && !root->right){
            sum = root->data;
            return true;
        }
        
        int leftSum = 0;
        int rightSum = 0;
        
        // check left subtree
        if(!computeSum(root->left, leftSum)){
            return false;
        }
        
        // check right subtree
        if(!computeSum(root->right, rightSum)){
            return false;
        }
        
        if(root->data != leftSum + rightSum){
            return false;
        }
        
        sum = root->data + leftSum + rightSum;
        
        return true;
    }
  
    bool isSumTree(Node* root) {
        // Your code here
        int sum = 0;
        return computeSum(root, sum);
    }
};