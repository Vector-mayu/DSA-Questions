class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        
        // Base Case
        if(!root){
          return NULL; // As this is a leaf node for BST dosent Exist
        }
        // Check for Left BST
        if(root->data > n1->data && root->data > n2->data){
          return LCA(root->left, n1, n2); // Recursively returns the target Node on Left
        }
        //Check for Right BST
        else if(root->data < n1->data && root->data < n2->data){
          return LCA(root->right, n1, n2); // Recusively returns the target Node on Right
        }
        else
        return root;
        
        
    }
};