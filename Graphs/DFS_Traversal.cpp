class Solution {
  public:
  
    void DFS(vector<vector<int>>&adj, int node, vector<bool>&visited, vector<int>&ans){
        
        visited[node] = 1;
        ans.push_back(node);
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                DFS(adj, neighbour, visited, ans);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        
        vector<bool>visited(v, 0);
        vector<int>ans;
        
        DFS(adj, 0, visited, ans);
        
        return ans;
    }
};