// GFG Hard Problem 

class Solution {
  public:
  
    TNode* BuildBST(vector<int>&Tree, int start, int end)
    {
        // Base Condition
        if(start>end){
          return NULL;
        }

        int mid = start + (end-start+1)/2; // Handles both even/odd Length of LL
        
        //Node
        TNode *root = new TNode(Tree[mid]);
        //Left
        root->left = BuildBST(Tree, start, mid-1);
        //Right
        root->right = BuildBST(Tree, mid+1, end);
        
        return root; //Return Root Address
    }
  
    TNode *sortedListToBST(LNode *head) {
        // code here
        
        vector<int>Tree; // Push All ll Data into Vector
        while(head)
        {
            Tree.push_back(head->data);
            head = head->next;
        }
        
        return BuildBST(Tree, 0, Tree.size()-1);
        
    }
};