class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
        return {};

        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            double sum = 0;

            for(int i=0; i<n; i++){
                TreeNode *temp = q.front();
                sum += (double)temp->val;

                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                q.pop();
            }
            double avg = sum/n;
            ans.push_back(avg);
        }

        return ans;
    }
};