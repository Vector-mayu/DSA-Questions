class Solution {
public:

    void findRange(TreeNode *root, int low, int high, int &ans){
        if(!root)
        return;

        if(root->val >= low && root->val <= high)
        ans += root->val;

        if(root->val >= low)
        findRange(root->left, low, high, ans);

        if(root->val <= high)
        findRange(root->right, low, high, ans);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        findRange(root, low, high, ans);
        return ans;
    }
};