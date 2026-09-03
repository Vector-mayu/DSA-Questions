class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>color(V, -1);
        
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                queue<int>q;
                q.push(i);
                
                color[i] = 0;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(int neib : adj[node]){
                        if(color[neib] == -1){
                            q.push(neib);
                            color[neib] = (color[node]+1)%2;
                        }
                        else if(color[neib] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};