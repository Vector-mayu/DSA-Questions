// TC :- O(V+E) its a DFS only
// SC :- O(V+E) Adjacency List

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>inDegree(V, 0);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int>q;
        for(int i=0; i<V; i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(int neib : adj[node]){
                inDegree[neib]--;
                if(!inDegree[neib]){
                    q.push(neib);
                }
            }
        }
        
        return V==count ? false : true;
    }
};