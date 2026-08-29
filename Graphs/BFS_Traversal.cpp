// TC :- O(V + 2E)
// SC :- O(v^2)

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();

        // create queue and visited array
        queue<int>q;
        vector<bool>visited(v, 0);
        q.push(0);
        visited[0] = 1;

        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            // traverse whole array ie all neighbours
            for(int neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};