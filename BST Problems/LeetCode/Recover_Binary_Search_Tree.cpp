
class Solution {
public:

    void inorderBST(TreeNode *root, vector<int>&ans){
        if(!root){
            return;
        }

        inorderBST(root->left, ans);
        ans.push_back(root->val);
        inorderBST(root->right, ans);
    }

    void replaceBST(TreeNode *root, int &n1, int &n2){
        if(!root)
        return;

        if(root->val == n1){
            root->val = n2;
        }
        else if(root->val == n2){
            root->val = n1;
        }

        replaceBST(root->left, n1, n2);
        replaceBST(root->right, n1, n2);

    }

    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorderBST(root, ans);

        int prev = ans[0];
        int n1, n2;
        bool isN1 = false;

        for(int i=1; i<ans.size(); i++){
            int curr = ans[i];

            if(prev > curr){
                if(!isN1){
                    n1 = prev;
                    isN1 = true;
                }
                n2 = curr;
            }
            prev = curr;
        }

        replaceBST(root, n1, n2);
    }
};