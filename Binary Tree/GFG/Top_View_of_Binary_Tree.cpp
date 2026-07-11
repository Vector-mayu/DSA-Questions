// TC :- O(N)
// SC :- O(H)
class Solution {
  public:
  
    void findPositions(Node *root, int &left, int &right, int pos){
        if(!root)
        return;
        
        left = min(left, pos);
        right = max(right, pos);
        
        findPositions(root->left, left, right, pos-1);
        findPositions(root->right, left, right, pos+1);
    }
  
    vector<int> topView(Node *root) {
        // code here
        int leftMost = 0, rightMost = 0;
        // this function will calculate leftmost value and rightmost value
        findPositions(root, leftMost, rightMost, 0);
        
        // this will calculate size of ans vector
        int size = rightMost - leftMost + 1;
        vector<int>ans(size, 0);
        
        // we will store node and its position
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        // this is simply level order traversal
        while(!q.empty()){
            Node *temp = q.front().first;
            int pos = q.front().second;
            q.pop();
            
            // is this particular node is my answer???
            int index = pos - leftMost;
            if(!ans[index]){ // if its 0
                ans[index] = temp->data;
            }
            // left and right traversal
            if(temp->left){
                q.push({temp->left, pos-1});
            }
            if(temp->right){
                q.push({temp->right, pos+1});
            }
        }
        
        return ans;
    }
};