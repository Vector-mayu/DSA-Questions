class Solution {
  public:
  
    void KLargest(Node *root, int &ans, int &k)
    {
        if(!root)
        return;
        
        // Go reverse of INORDER traversak (LNR--->RNL)
        
        //Right
        KLargest(root->right, ans, k);
        k--;
        
        if(k==0)
        ans = root->data;
        
        if(k<=0)
        return;
        
        //Left
        KLargest(root->left, ans, k);
    }
  
    int kthLargest(Node *root, int k) {
        // Your code here
        
        int ans;
        KLargest(root, ans, k);
        return ans;
    }
};