class Solution {
public:
    int checkBalance(TreeNode *root){
        if(!root)
        return 0;

        // Leaf Node
        if(!root->left && !root->right)
        return 1;

        // if any where we get -1 that means Tree is not balanced
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

    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};