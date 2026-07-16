class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case
        if(!root)
        return nullptr;

        if(val < root->val){
            return searchBST(root->left, val);
        }
        else if(val > root->val){
            return searchBST(root->right, val);
        }
        else{
            TreeNode *ans = root;
            if(root->left)
            ans->left = root->left;
            if(root->right)
            ans->right = root->right;
            return ans;
        }

        return nullptr;
    }
};