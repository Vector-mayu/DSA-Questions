class Solution {
public:

    void find(TreeNode *root, int &result, int &k){
        if(!root || k <= 0)
        return;

        // left for finding the smallest value
        find(root->left, result, k);
        k--;

        // check if k is zero or not
        if(k == 0){
            result = root->val;
            return;
        }

        find(root->right, result, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        find(root, result, k);

        return result;
    }
};