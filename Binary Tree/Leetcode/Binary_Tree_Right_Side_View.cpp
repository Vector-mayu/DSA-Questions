// TC :- O(N)
// SC :- Recursion(stack = O(N)) -> O(N) 
// if Tree is Skewed Space = O(N)
// if Tree is Balanced Space = O(logn)
class Solution {
public:

    void Rview(TreeNode *root, vector<int>&ans, int level){
        if(!root)
        return;

        // we will follow preorder but 
        // right first and then left
        // NRL -> because we need the rightmost element first
        if(ans.size() == level)
        ans.push_back(root->val);

        Rview(root->right, ans, level+1);
        Rview(root->left, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        return {};

        vector<int>ans;

        Rview(root, ans, 0);

        return ans;
    }
};