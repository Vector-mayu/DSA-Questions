class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
        return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>ans;
        while(!q.empty()){
            int n = q.size();

            vector<int>arr;
            for(int i=0; i<n; i++){
                TreeNode *temp = q.front();
                arr.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
            }
            ans.push_back(arr);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};