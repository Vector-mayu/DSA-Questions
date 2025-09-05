class Solution {
  public:
  
    bool DeadEnd(Node *root, int lower, int upper)
    {
        //Base Condition
        if(!root)
        return 0;
        
        //If i reach the Leaf Node
        if(!root->left && !root->right)
        {
            //Check the difference between root data
            if(root->data-lower==1 && upper-root->data==1)
            return 1;
            else
            return 0;
        }
        
        // Left Range || right Range (if anyone is 1 then its not a DeadEnd)
        return DeadEnd(root->left, lower, root->data) || DeadEnd(root->right, root->data, upper);
    }
  
    bool isDeadEnd(Node *root) {
        
        return DeadEnd(root, 0, INT_MAX);   
    }
};