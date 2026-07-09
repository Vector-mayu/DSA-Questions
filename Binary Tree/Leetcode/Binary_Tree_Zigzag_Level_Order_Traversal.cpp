class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;
        int index = 1;

        q.push(root);
        while(!q.empty()){
            int n = q.size();

            vector<int>arr;
            while(n){
                arr.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
                n--;
            }

            if(index % 2 == 0){
                reverse(arr.begin(), arr.end());
            }

            index++;
            ans.push_back(arr);
        }

        return ans;
    }
};