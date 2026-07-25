// Approach 1 :- Extra Space
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

// Optimized Approach :- O(N), O(N)

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

    void inorder(TreeNode *root, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
        if(!root)
        return;
        
        // left side first
        inorder(root->left, first, second, prev);
        
        // check for voilation of node
        if(prev && (root->val < prev->val)){
            // first number 
            TreeNode *curr = root;
            if(!first){
                first = prev; // direct assign with address
            }
            // always update second
            second = curr;
        }
        // Update Prev mannnnn
        prev = root;
        
        // right side last
        inorder(root->right, first, second, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        
        inorder(root, first, second, prev);
        
        swap(first->val, second->val);
    }
};