class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>color(v, -1);
        for(int i=0; i<v; i++){
            if(color[i] == -1){
                queue<int>q;
                q.push(i);
        
                color[i] = 0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int neib : graph[node]){
                        if(color[neib] == -1){
                            q.push(neib);
                            color[neib] = (color[node]+1)%2;
                        }
                        else if(color[neib] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};