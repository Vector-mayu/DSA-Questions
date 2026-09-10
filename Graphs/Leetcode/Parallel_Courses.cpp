class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        // code here
        int V = n+1;
        vector<vector<int>>adj(V);
        vector<int>inDegree(V, 0);

        for(auto edge : relations){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int>q;
        for(int i=1; i<V; i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }

        int mini = 0;

        while(!q.empty()){
            mini++;
            int size = q.size();
            int courses = min(size, k);

            for(int i=0; i<courses; i++){
                int node = q.front();
                q.pop();
                
                for(int neib : adj[node]){
                    inDegree[neib]--;
                    if(inDegree[neib] == 0){
                        q.push(neib);
                    }
                }
            }
        }

        return mini;
    }
};