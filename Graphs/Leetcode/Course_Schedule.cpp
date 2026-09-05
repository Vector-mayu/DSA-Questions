class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses, 0);

        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            count++;
            q.pop();

            // decrease the inDegree of Neighbours
            for(int neib : adj[node]){
                inDegree[neib]--;
                if(inDegree[neib] == 0){
                    q.push(neib);
                }
            }
        }

        return count == numCourses ? true : false;
    }
};