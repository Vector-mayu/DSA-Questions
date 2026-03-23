// TC -> O(V+E) ~ O(V^2)
// SC -> O(N + N) ~ O(N)
//     Stack + vector

class Solution {
  public:
  
    void DFS(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s){
        // mark visited 1
        visited[node] = 1;
        
        // find all the neighbour and DFS it
        for(int j=0; j<adj[node].size(); j++){
            if(!visited[adj[node][j]]){
                DFS(adj[node][j], adj, visited, s);
            }
        }
        
        // if there is no next or all nodes are visited
        // then push itself in to stack
        s.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }
        
        // here we need 1 visited vector 
        // and a stack to keep the values which ended first
        stack<int>s;
        vector<bool>visited(V,0);
        
        // calculate DFS for all the node 
        // for loop to do DFS for all node as well as missing nodes
        for(int i=0; i<V; i++){
            if(!visited[i])
            DFS(i, adj, visited, s);
        }
        
        // Create a final answer
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};