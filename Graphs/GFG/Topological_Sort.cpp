// TC -> O(V+E) ~ O(V^2)
// SC -> ~ O(N)


class Solution {
  public:
  
    void DFS(vector<vector<int>>&adj, vector<bool>&visited, vector<int>&ans, int node){
        visited[node] = 1;
        
        for(int neib : adj[node]){
            if(!visited[neib]){
                DFS(adj, visited, ans, neib);
            }
        }
        
        ans.push_back(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        // edges -> adjacency list
        for(auto edge : edges){
            // Direct Acyclic Graph
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int>ans;
        vector<bool>visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                DFS(adj, visited, ans, i);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};