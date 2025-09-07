// GeeksForGeeks Hard Problem

class Solution {
  public:
  
    int Height(Node *root)
    {
        if(!root)
        return 0;
        
        return 1 + max(Height(root->left), Height(root->right));
    }
  
    void find(Node *root, int target, Node * &BurnNode)
    {
        if(!root)
        return;
        
        if(root->data == target)
        {
            BurnNode = root;
            return;
        }
        
        find(root->left, target, BurnNode);
        find(root->right, target, BurnNode);
    }
  
    int Burn(Node *root, int &timer, int target)
    {
        if(!root) // if leaf or not exit condition
        return 0;
        
        if(root->data == target) // if exist and is equal to burn node
        return -1;
        
        // recursively go in both direction 
        int left = Burn(root->left, timer, target);
        int right = Burn(root->right, timer, target);
        
        // burn node is either in RIGHT or LEFT
        
        // Case 1 : if left has the burn Node 
        if(left < 0)
        {
            timer = max(timer, (abs(left) + right)); // store max of right and left in positive number
            return left - 1;
        }
        //Case 2 : if right has the burn node 
        if(right < 0)
        {
            timer = max(timer, (left + abs(right)));
            return right - 1;
        }
        
        return 1 + max(left , right); // if no condition is satisfied
        
    }
  
    int minTime(Node* root, int target) {
        // code here
        
        int timer = 0; // defines max time took to burn in a tree from left and right
        Burn(root, timer, target);
        
        // if we consider fire node as root node then go ahead and find the rest height of fire
        
        Node *BurnNode = NULL;
        find(root, target, BurnNode); // This Function finds the position of Burn Node
        
        int high = Height(BurnNode)-1; // This returns height of Rest of tree 


        return max(timer, high); // Which ever is max it will get returned
        
        
    }
};