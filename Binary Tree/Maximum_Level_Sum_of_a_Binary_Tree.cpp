/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int level = 1; // as question said consider root as level 1
        int ans = 1;

        // we will use logic of level order traversal
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            // this calculates total sum of that level
            int tempSize = 0;

            while(size--){
                TreeNode *temp = q.front();
                q.pop();
                tempSize += temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            // if the current level has bigger sum
            // we will update maxSum
            // and we will update ans to max level
            if(maxSum < tempSize){
                maxSum = tempSize;
                ans = level;
            }
            level++;
        }

        return ans;
    }
};