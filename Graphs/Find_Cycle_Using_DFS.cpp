class Solution {
  public:
  
    bool DetectCycle(int node, int parent, vector<vector<int>>&Adj, vector<int>&Visited){
        Visited[node] = 1;
        
        for(int j=0; j<Adj[node].size(); j++){
            
            // case 1 : If its equal to parent(Previous) node
            if(Adj[node][j] == parent)
            continue;
            
            // case 2 : If Cycle is Detected 
            if(Visited[Adj[node][j]])
            return 1;
            
            //case 3 : If Cycle is Detected anywhere in this Recursive call then immediatly return 1
            if(!Visited[Adj[node][j]]){
                if(DetectCycle(Adj[node][j], node, Adj, Visited)){
                    return 1;
            }   }
        }
        
        return 0;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>Adj(V);
        vector<int>Visited(V,0);
        
        // Make Adjacency List with Adjacency Edges
        for(int i=0; i<edges.size(); i++){
           int u = edges[i][0];
           int v = edges[i][1];
           
           Adj[u].push_back(v);
           Adj[v].push_back(u); // Undirected Graph
        }
        
        for(int i=0; i<V; i++){ // There are more than 1 components in Graph
            if(!Visited[i]){
                if(DetectCycle(i, -1, Adj, Visited))
                // Visited of i is zero and DetectCycle is also 1 then return 1
                return true;
            }
        }
        
        return false;
    }
};