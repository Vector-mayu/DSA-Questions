class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        // make adjacency list
                // calculate inDegree
                // apply topological sort
                // stor ans of top in vector
                // process in topo sort order
                    // 1. if node itself is -1 then -> skip
                    // if neib is -1 then (we are visiting first time)
                    // if neib exist then update the samllaest weights
                vector<vector<pair<int, int>>>adj(V);
                vector<int>inDegree(V);

                for(auto edge : edges){
                    int u = edge[0];
                    int v = edge[1];
                    int wt = edge[2];

                    adj[u].push_back({v, wt});
                    inDegree[v]++;
                }

                queue<int>q;

                for(int i=0; i<V; i++){
                    if(inDegree[i] == 0){
                        q.push(i);
                    }
                }

                vector<int>topoSort;
                // topo sort algo
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    topoSort.push_back(node);

                    for(auto p : adj[node]){
                        int neib = p.first;
                        inDegree[neib]--;

                        if(inDegree[neib] == 0){
                            q.push(neib);
                        }
                    }
                }

                vector<int>dist(V, -1);
                dist[0] = 0;

                for(int i=0; i<V; i++){
                    int node = topoSort[i];

                    // if node itself is -1 then its not after 0 -> skip
                    if(dist[node] == -1){
                        continue;
                    }

                    for(auto p : adj[node]){
                        int neib = p.first;
                        int wt = p.second;

                        // if visting first time
                        if(dist[neib] == -1){
                            dist[neib] = dist[node] + wt;
                        }
                        else{
                            dist[neib] = min(dist[neib], dist[node] + wt);
                        }
                    }
                }

                return dist;
    }
};
