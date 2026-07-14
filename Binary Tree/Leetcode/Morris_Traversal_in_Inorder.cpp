// Space Complexity = O(1) // not recursion no stack -> O(1)
// TC :- O(N) // we visit each node 3-4 times still O(N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Iorder traversal using MORRIS TRAVERSAL
        if(!root)
        return {};

        vector<int>ans;

        TreeNode *curr = root;

        while(curr){
            // if curr left not exist
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            // if left exist then game begins
            else{
                TreeNode * pred = curr->left;
                // move to right untill ans unless we get NULL or curr node
                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }
                // after going right continously 
                // case 1 :- we got the right node as null
                if(!pred->right){
                    // then point it to root node whichever curr is running
                    pred->right = curr;
                    curr = curr->left;
                }
                // case 2 :- it pointed to root itself -> means we alread visited this left side
                else{
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};