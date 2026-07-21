class Solution {
  public:
  
    Node *createBST(Node *root, int val){
        if(!root)
        return new Node(val);
        
        if(val < root->data)
        root->left = createBST(root->left, val);
        else
        root->right = createBST(root->right, val);
        
        return root;
    }
  
    Node* preToBST(vector<int>& pre) {
        // code here
        Node *root = new Node(pre[0]);
        
        for(int i=1; i<pre.size(); i++){
            createBST(root, pre[i]);
        }
        
        return root;
    }