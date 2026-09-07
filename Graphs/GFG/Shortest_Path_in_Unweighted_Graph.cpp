class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adj(V);

                for(auto edge : edges){
                    int u = edge[0];
                    int v = edge[1];

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }

                vector<int>dist(V, -1);
                dist[src] = 0;

                queue<int>q;
                q.push(src);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int neib : adj[node]){
                        // if -1 then its not visited bro
                        if(dist[neib] == -1){
                            dist[neib] = dist[node] + 1;
                            q.push(neib);
                        }
                    }
                }


            return dist[dest];
    }
};
