// TC :- O(V + 2E)
// SC :- O(v^2)

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
        queue<int>q;
        vector<bool>Visited(v, 0);
        vector<int>ans;
        
        //Push 1st Element ans mark visited as 1
        q.push(0);
        Visited[0] = 1;
        int node;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            ans.push_back(node); // update final answer
            
            // Check Current element Neighbour Nodes and push them into Queue
            for(int j=0; j<adj[node].size(); j++){
                if(!Visited[adj[node][j]]){
                    Visited[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }
        
        return ans;
    }
};