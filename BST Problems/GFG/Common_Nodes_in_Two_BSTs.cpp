class Solution {
  public:
  
    void totalNodes(Node *root, map<int, int>&mp){
        if(!root)
        return;
        
        mp[root->data]++;
        totalNodes(root->left, mp);
        totalNodes(root->right, mp);
    }
  
    vector<int> findCommon(Node* r1, Node* r2) {
        // code here
        map<int, int>mp;
        vector<int>ans;
        
        totalNodes(r1, mp);
        totalNodes(r2, mp);
        
        for(auto &x : mp){
            if(x.second >= 2)
            ans.push_back(x.first);
        }
        
        return ans;
    }
};