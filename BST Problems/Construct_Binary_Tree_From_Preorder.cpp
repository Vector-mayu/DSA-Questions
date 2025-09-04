class Solution {
public:

    TreeNode* BST(vector<int>&preorder, int &index, int lower, int upper)
    {
        //base Conditon 
        if(index >= preorder.size() || preorder[index]<lower || preorder[index]>upper)
        return NULL;

        //Node
        TreeNode *root = new TreeNode(preorder[index++]);
        //Left Node 
        root->left = BST(preorder, index, lower, root->val);
        //Right Node
        root->right = BST(preorder,index,root->val, upper);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0; // Iterator
        return BST(preorder, index, INT_MIN, INT_MAX);
    }
};
