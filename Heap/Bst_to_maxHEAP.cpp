//  GFG Medium Problem 
  // Company :- DE Shaw

class Solution {
  public:
  
    void InorderTraversal(Node *root, vector<int>&ans)
    {
        if(!root)
        return;
        
        // INORDER Traversal (LNR)
        
        // Left Side
        InorderTraversal(root->left, ans);
        //Node 
        ans.push_back(root->data);
        // Right Side
        InorderTraversal(root->right, ans);
    }
    
    void PostorderTraversal(Node *root, int &index, vector<int>&ans)
    {
        if(!root)
        return;
        
        // POSTORDER Traversal (LRN)
        
        //Left Side
        PostorderTraversal(root->left, index, ans);
        // Right Side
        PostorderTraversal(root->right, index, ans);
        // Push Into Node
        root->data = ans[index++];
        

    }
    
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        
        vector<int>ans;
        
        InorderTraversal(root,ans);
        
        int index = 0;
        PostorderTraversal(root, index, ans);
        
        
    }
};
