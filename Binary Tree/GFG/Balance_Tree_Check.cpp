class Solution {
  public:
  
    int checkBalance(Node *root){
        if(!root)
        return 0;
        
        if(!root->left && !root->right){
            return 1;
        }
        
        int left = checkBalance(root->left);
        if(left == -1)
        return -1;
        int right = checkBalance(root->right);
        if(right == -1)
        return -1;
        
        if(abs(left-right) > 1)
        return -1;
        
        return 1 + max(left, right);
    }
  
    bool isBalanced(Node* root) {
        // code here
        return checkBalance(root) != -1;
    }
};