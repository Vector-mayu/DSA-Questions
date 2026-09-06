class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);

        vector<int>inDegree(n, 0);
        for(auto course : prerequisites){
            adj[course[1]].push_back(course[0]);
            inDegree[course[0]]++;
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int neib : adj[node]){
                inDegree[neib]--;
                if(inDegree[neib] == 0){
                    q.push(neib);
                }
            }
        }

        if(ans.size() != n){
            return {};
        }

        return ans;
    }
};