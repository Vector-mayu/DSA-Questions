class Solution {
  public:
  
    void inorder(Node *root, vector<int>&ans)
    {
        if(!root)
        return;
        
        // Left 
        inorder(root->left, ans);
        // Node 
        ans.push_back(root->data);
        // Right
        inorder(root->right, ans);
    }
  
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        
        vector<int>ans1; // Vector which stores BST1
        vector<int>ans2; // Vector which stores BST2
        
        inorder(root1, ans1);
        inorder(root2, ans2);
        
        vector<int>final; // Vector which stores merged BST
        
        int i = 0, j = 0;
        while(i<ans1.size() && j<ans2.size()) // Compare it until both exist
        {
            if(ans1[i] < ans2[j])
            final.push_back(ans1[i++]);
            else
            final.push_back(ans2[j++]);
        }
        
        while(i<ans1.size()) // If ans1 vector is still not empty
        final.push_back(ans1[i++]);
        
        while(j<ans2.size()) // If ans2 vector is still not empty
        final.push_back(ans2[j++]); 
        
        return final;
        
    }
};