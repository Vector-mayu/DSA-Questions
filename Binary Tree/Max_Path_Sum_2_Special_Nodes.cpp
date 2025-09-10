// Max Path Sum 2 Special Nodes .... Difficulty : Hard

class Solution {
  public:
  
    int Paths(Node *root , int &sum)
    {
        if(!root)
        return 0;
        
        if(!root->left && !root->right)
        return root->data;
        
        int left = Paths(root->left, sum);
        int right = Paths(root->right, sum);
        
        // If left and right both exist 
        if(root->left && root->right)
        {
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }
        
        // Only left part exist 
        if(root->left)
        {
            return root->data + left;
        }
        
        // Only right part exist
        if(root->right)
        {
            return root->data + right;
        }
        
    }
  
    int maxPathSum(Node* root) {
        // code here
        
        int sum = INT_MIN;
        int value = Paths(root, sum);
        
        if(root->left && root->right)
        return sum;
        
        return max(value, sum);
    }
};