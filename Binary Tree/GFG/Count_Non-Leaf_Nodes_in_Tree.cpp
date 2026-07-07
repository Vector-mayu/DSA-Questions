class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
        if (!root)
            return 0;

        // Leaf node
        if (!root->left && !root->right)
            return 0;

        // Current node is a non-leaf
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};