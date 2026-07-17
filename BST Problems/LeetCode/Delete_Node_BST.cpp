class Solution {
public:

    TreeNode *find(TreeNode *root){
        TreeNode *curr = root->left;
        while(curr->right){
            curr = curr->right;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // EDGE CASES Problem

        if(!root)
        return nullptr;

        // key is lesser go in Left
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        //Key is bigger go in Right
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        // got that key its deletion time now
        else{
            // Leaf Node
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // both sides exist man
            else{
                // find will give me the largest value from right side
                TreeNode *pred = find(root);
                // now pred has the largest value to its lefts -> right
                root->val = pred->val;
                // we will call the OG fun again as we will recursively delete the node 
                // inorder to tackle root conditons where we have deep penetrations
                // by calling deleteNode Function again will recursivley solve problem

                root->left = deleteNode(root->left, pred->val);
            }
        }

        return root;
    }
};