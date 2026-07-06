class Solution {
  public:
  
    void preorder(Node *root, int &sum){
        if(root == nullptr)
        return;
        
        sum += root->data;
        preorder(root->left, sum);
        preorder(root->right, sum);
    }
  
    int sumBT(Node* root) {
        // code here
        int sum = 0;
        
        preorder(root, sum);
        
        return sum;
    }
};