class Solution {
public:

    int getSize(TreeNode *root){
        if(!root)
        return 0;

        return 1 + getSize(root->left) + getSize(root->right);
    }

    bool checkCBT(TreeNode *root, int index, int n){
        if(!root) return true;

        if(index >= n) return false;

        return checkCBT(root->left, 2*index+1, n) && checkCBT(root->right, 2*index+2, n);
    }

    bool isCompleteTree(TreeNode* root) {
        int size = getSize(root);

        // this is max heap style couting to check the completeness of Tree
        // if left in any level they dont follow left -> right ordering this will return false
        int index = 0;
        return checkCBT(root, index, size);
    }
};