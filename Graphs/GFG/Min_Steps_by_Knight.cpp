class Solution {
  public:
  
    bool isValid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
  
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        //edge case -> if src and dest is the same point
        if(knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]){
            return 0;
        }
        
        // the grid is 1 indexed grid 
        // convert it into 0 indexed grid
        
        knightPos[0]--;
        knightPos[1]--;
        targetPos[0]--;
        targetPos[1]--;
        
        // BFS -> Queue
        queue<pair<int, int>>q;
        q.push({knightPos[0], knightPos[1]});
        
        // visited vector
        vector<vector<bool>>visited(n, vector<bool>(n, 0));
        visited[knightPos[0]][knightPos[1]] = 1;
        
        int totalStep = 0;
        while(!q.empty()){
            int size = q.size();
            totalStep++;
            
            int row[8] = {1, -1, 1, -1, 2, -2, 2, -2};
            int col[8] = {2, 2, -2, -2, 1, 1, -1, -1};
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k=0; k<8; k++){
                    int a = i + row[k], b = j + col[k];
                    
                    if(isValid(a, b, n) && visited[a][b] == 0){
                        if(a == targetPos[0] && b == targetPos[1]){
                            return totalStep;
                        }
                        
                        q.push({a, b});
                        visited[a][b] = 1;
                    }
                    
                }
            }
        }
        
        return -1;
    }
};