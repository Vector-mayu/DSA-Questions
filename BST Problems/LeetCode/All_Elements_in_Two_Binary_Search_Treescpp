class Solution {
public:

    void traverse(TreeNode *root, vector<int>&ans){
        if(!root)
        return;

        ans.push_back(root->val);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 &&  !root2){
            return {};
        }
        
        vector<int>ans;
        traverse(root1, ans);
        traverse(root2, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};