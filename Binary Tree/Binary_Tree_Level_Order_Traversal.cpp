// TC :- O(N)
// SC :- O(N/2) ~ O(N)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i=0; i<size; i++){
                TreeNode *curr = q.front();
                temp.push_back(curr->val);
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};