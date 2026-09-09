class Solution {
public:

    void DFS(vector<vector<int>>&adj, vector<bool>&visited, int node){
        visited[node] = 1;

        for(int neib : adj[node]){
            if(visited[neib] == 0){
                DFS(adj, visited, neib);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>>adj(V+1);

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        // now simple DFS algo will work
        vector<bool>visited(V+1, 0);
        int provinces = 0;

        for(int i=0; i<V; i++){
            if(!visited[i]){
                provinces++;
                DFS(adj, visited, i);
            }
        }

        return provinces;
    }
};