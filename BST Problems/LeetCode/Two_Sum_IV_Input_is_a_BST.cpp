class Solution {
public:

    void makeBST(TreeNode *root, vector<int>&ans){
        if(!root)
        return;

        makeBST(root->left, ans);
        ans.push_back(root->val);
        makeBST(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        makeBST(root, ans);

        int start = 0, end = ans.size()-1;

        int result = INT_MAX;
        while(start < end){
            int sum = ans[start] + ans[end];

            if(sum < k){
                start++;
            }
            else if(sum > k){
                end--;
            }
            else{
                result = sum;
                break;
            }
        }
        if(result != INT_MAX)
        return true;

        return false;
    }
};