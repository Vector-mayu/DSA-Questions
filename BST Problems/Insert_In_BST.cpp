class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // whenever it gets null we know it has got its location to insert
        if(!root){
            TreeNode *node = new TreeNode(val);
            return node;
        }
        
        // left cond
        if(val <= root->val){
            root->left = insertIntoBST(root->left, val);
        }
        // right condition 
        else if(val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
};