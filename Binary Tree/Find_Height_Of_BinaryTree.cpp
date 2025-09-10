class Solution {
  public:
    int height(Node* root) {
        if (root == NULL)
            return -1; // empty tree has -1 edges
         
        return 1 + max(height(root->left), height(root->right)); // Retunr 1 + the recursive call for left and right side
    }
};