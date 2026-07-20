class Solution {
public:

    bool checkValidBST(TreeNode *root, long long minValue, long long maxValue){
        if(!root)
        return 1;

        if(root->val <= minValue || root->val >= maxValue)
        return 0;

        return checkValidBST(root->left, minValue, root->val) && checkValidBST(root->right, root->val, maxValue);

    }

    bool isValidBST(TreeNode* root) {
        // we will use the concept of min max (INT_MAX, INT_MIN)
        // if we go on left side the INT_MAX changes to current nodes value 
        // if we go on right side the INT_MIN changes to current node

        return checkValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};