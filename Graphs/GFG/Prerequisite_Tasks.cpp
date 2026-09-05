class Solution {
  public:
    bool isPossible(int n, vector<pair<int, int>>& pre) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>inDegree(n, 0);
        // constructing Adjacency 
        for(auto edge : pre){
            int u = edge.first;
            int v = edge.second;
            
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
        queue<int>q;
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            count++;
            q.pop();
            
            for(int neib : adj[node]){
                inDegree[neib]--;
                if(inDegree[neib] == 0){
                    q.push(neib);
                }
            }
        }
        
        return count == n ? true : false; 
        
        
    }
};