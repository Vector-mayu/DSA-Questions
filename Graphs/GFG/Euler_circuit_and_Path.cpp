class Solution {
public:

    void DFS(vector<int>adj[], int node, vector<bool>&visited){
        visited[node] = 1;

        for(auto neib : adj[node]){
            if(!visited[neib]){
                DFS(adj, neib, visited);
            }
        }
    }

    int isEulerCircuit(int V, vector<int> adj[]) {
        // Calculate Degree's for each node
        vector<int>Degree(V, 0);
        for(int i=0; i<V; i++){
            Degree[i] = adj[i].size();
        }

        // count the number of nodes having ODD degree
        int oddDeg = 0;
        for(int i=0; i<V; i++){
            if(Degree[i]%2){
                oddDeg++;
            }
        }

        // we need exactly 0 or 2 ODD nodes degree in graph network
        // Euler path :- 1
        // Euler circuit :- 2
        // Both no :- 0
        if(oddDeg != 0 && oddDeg != 2){
            return 0;
        }

        vector<bool>visited(V, 0);

        for(int i=0; i<V; i++){
            if(Degree[i]){
                // traverse only once
                DFS(adj, i, visited);
                break;
            }
        }

        // check if multiple Graph components are there or not
        // Multiple Graphs not allowed
        for(int i=0; i<V; i++){
            if(!visited[i] && Degree[i])
            return 0;
        }

        // last check
        // if total odd nodes are 0 then its Euler circuit
        // if total odd nodes are 2 then its Euler Path only

        return oddDeg ? 1 : 2;

    }
};