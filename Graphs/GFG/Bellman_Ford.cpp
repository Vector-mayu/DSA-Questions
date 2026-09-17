class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // while traversing over the edges vector we will relax the edges accordingly
        vector<int>dist(V, 100000000);
        dist[src] = 0;
        
        for(int i=0; i<V-1; i++){
            for(auto edge : edges){
               int u = edge[0];
               int v = edge[1];
               int w = edge[2];
               
               // if u is already infinite then skip it man
              if(dist[u] == 100000000){
                    continue;
                }
                
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // one last iteration to check if 
        // negatice cycle condition
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            // this mean there is a negative cycle it
            if(dist[u] != 100000000 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};
