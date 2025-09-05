int n1, n2; // GLOBAL VARIABLE
class Solution {
  public:
  
    void find(Node *root, vector<int>&ans)
    {
        //Base Condition
        if(!root)
        return;
        
        //Recursively find in left within the range
        if(root->data>n1 && root->data>n2){
            return find(root->left, ans);
        }
        //Recursively find in Right within the range
        else if(root->data<n1 && root->data<n2){
            return find(root->right, ans);
        }
        // We got the Node Within the range
        else{
            // Left side
            find(root->left, ans);
            // Node
            ans.push_back(root->data);
            // Right Side
            find(root->right, ans);
        }
    }
  
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        
        n1 = low;
        n2 = high;
        vector<int>ans;
        find(root, ans);
        return ans;
    }
};