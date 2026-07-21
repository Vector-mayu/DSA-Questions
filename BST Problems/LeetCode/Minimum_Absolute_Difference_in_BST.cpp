class Solution {
public:

    void getDifference(TreeNode *root, int &diff, int &prev){
        if(!root)
        return;

        getDifference(root->left, diff, prev);

        // if diff is INT_MIN then skip 
        if(prev != INT_MIN)
        diff = min(diff, root->val-prev);

        prev = root->val;

        getDifference(root->right, diff, prev);
    }

    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevValue = INT_MIN;
        getDifference(root, minDiff, prevValue);

        return minDiff;
    }
};