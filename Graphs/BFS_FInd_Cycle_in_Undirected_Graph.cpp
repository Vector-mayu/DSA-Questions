TC :- O(V + E)
V nodes and each haivng their E edges to visit

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<vector<int>>& edges) {
    // edges to adjacency list
    vector<vector<int>>adj(V);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<bool>visited(V, 0);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            // pair of {node, parent}
            queue<pair<int, int>>q;
            q.push({i, -1});

            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(int neib : adj[node]){
                    if(neib != parent){
                        if(visited[neib]){
                            return 1;
                        }
                        else{
                            visited[neib] = 1;
                            q.push({neib, node});
                        }
                    }
                }
            }
        }
    }

    return 0;
}