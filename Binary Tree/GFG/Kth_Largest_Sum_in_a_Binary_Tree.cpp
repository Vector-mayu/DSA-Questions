class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            long long sum = 0;

            for(int i=0; i<n; i++){
                TreeNode *temp = q.front();
                q.pop();

                sum += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(sum);
        }

        sort(ans.rbegin(), ans.rend());

        if(k > ans.size())
        return -1;

        return ans[k-1];
    }
};