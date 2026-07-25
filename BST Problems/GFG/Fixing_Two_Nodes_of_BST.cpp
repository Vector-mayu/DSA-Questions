class Solution {
  public:
  
    void inorder(Node *root, Node* &first, Node* &second, Node* &prev){
        if(!root)
        return;
        
        // left side first
        inorder(root->left, first, second, prev);
        
        // check for voilation of node
        if(prev && (root->data < prev->data)){
            // first number 
            Node *curr = root;
            if(!first){
                first = prev; // direct assign with address
            }
            // always update second
            second = curr;
        }
        // Update Prev mannnnn
        prev = root;
        
        // right side last
        inorder(root->right, first, second, prev);
    }
  
    Node* correctBST(Node* root) {
        // code here
        Node *first = nullptr, *second = nullptr, *prev = nullptr;
        
        inorder(root, first, second, prev);
        
        swap(first->data, second->data);
        
        return root;
    }
};