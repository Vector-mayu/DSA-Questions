class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>>adj(V);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        
        vector<bool>visited(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        
        int cost = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            
            // if already visited then skip
            if(visited[node]){
                continue;
            }
            
            visited[node] = 1;
            cost += w;
            
            // push all the neigbours into min-heap
            for(auto neib : adj[node]){
                int vneib = neib.first;
                w = neib.second; 
                
                if(!visited[vneib]){
                    pq.push({w, vneib});
                }
            }
        }
        
        return cost;
    }
};