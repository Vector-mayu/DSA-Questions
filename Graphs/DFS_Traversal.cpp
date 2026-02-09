// Time Complexity :- O(V + E)
// Space Complexity :- O(V)

class Solution {
  public:
  
  void DFStraversal(int node, vector<vector<int>>&adj, vector<int>&ans, vector<bool>&Visited){
      Visited[node] = 1;
      ans.push_back(node);
      
      for(int j=0; j<adj[node].size(); j++){
          if(!Visited[adj[node][j]]){
            DFStraversal(adj[node][j], adj, ans, Visited);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<int>ans;
        vector<bool>Visited(v, 0);
        
        DFStraversal(0, adj, ans, Visited);
        
        return ans;
    }
};