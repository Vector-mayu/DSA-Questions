bool findCycle(vector<vector<int>>&adj, vector<bool>&visited, int node, int dad){
    // whatever the node comes mark visited first 
    visited[node] = 1;

    // now lets go Deep DFS for that node
    for(int neib : adj[node]){
        if(neib == dad){
            continue;
        }
        // if visited is 1 then immediately return True
        else if(visited[neib]){
            return true;
        }
        else{
            if(findCycle(adj, visited, neib, node)){
                return true;
            }
        }
    }

    return 0;
};

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<vector<int>>& edges) {
    // we have been given edges 
    // lets convert edegs into Adjacency List

    vector<vector<int>>adj(V);
    for(auto edge : edges){
        // i will get edge as 1D array
        // edges contain only 0 and 1 indices in each 1D array
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // now we will do DFS for whole graph
    // but we also have many graphs in the network
    // they maybe conected to eachother or n number of independant graphs

    vector<bool>visited(V, 0);

    // we will iterate overall the vertices 
    // so that we also cover all independant graphs in the whole network

    for(int i=0; i<V; i++){
        if(!visited[i]){
            // if this is True then immediately return true dont check other graphs
            if(findCycle(adj, visited, i, -1))
            return true;
        }
    }

    return 0;
}