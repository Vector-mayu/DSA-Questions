// GFG Medium Problem
// Company :- Hike

class Solution {
  public:
  
    int CountNodes(Node *tree)
    {
        if(!tree)
        return 0;
        
        return 1 + CountNodes(tree->left) + CountNodes(tree->right);
    }
    
    bool CheckCBT(Node *tree, int index, int size)
    {
        if(!tree)
        return 1;
        
        if(index >= size)
        return 0;
        
        // If any Node on left 
        // If both sides are True then return True(1) or return False(0)
        return CheckCBT(tree->left, 2*index+1, size) && CheckCBT(tree->right, 2*index+2, size);

         //   Check on left side
         // CheckCBT(tree->left, 2*index+1, size);
         //    Check on Right side
         // CheckCBT(tree->right, 2*index+2, size);
        
    }
    
    bool maxHeap(Node *tree)
    {
        // Check Property on Left Side
        if(tree->left)
        {
            if(tree->data < tree->left->data)
            return 0;
            
            // Recursively return true or false
            if(!maxHeap(tree->left))
            return 0;
        }
        
        // Check Property on Right Side
        if(tree->right)
        {
            if(tree->data < tree->right->data)
            return 0;
            
            return maxHeap(tree->right); 
            // Here we directly return this because 
            // We reach on right side only if all left
            // Nodes are Valid , if We directly return in 
            // Left side then we cant check the right side
        }
        
        return 1;
    }
  
    bool isHeap(Node* tree) {
        // code here
        
        // STEP1 : Count The Total Number of Trees
        // Store the Count of node in 'size' 
        int size = CountNodes(tree); // size = Total size of Tree
        
        //STEP2 : Calculate if Tree is CBT(Complete Binary Tree) or not
        // Store it in Boolean Format (1/0)
        bool cbt = CheckCBT(tree, 0, size);
        
        // If Its not a CBT
        if(cbt == 0)
        return 0;
        
        //STEP3 : Check maxHeap Properties 
        // Check maxHeap and return (0/1)
        return maxHeap(tree);
        
        
    }
};