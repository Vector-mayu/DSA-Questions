class Solution {
public:

    bool isValid(int i, int j, int r, int c){
        return i>=0 && j>=0 && i<r && j<c;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int r = grid.size();
        int c = grid[0].size(); 

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int timer = 0;

        while(!q.empty()){
            int currentSize = q.size();
            timer++;

            while(currentSize--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int row[4] = {0, 0, -1, 1};
                int col[4] = {-1, 1, 0, 0};

                for(int k = 0; k<4; k++){
                    int a = i+row[k], b = j+col[k];
                    if(isValid(a, b, r, c) && grid[a][b] == 1){
                        q.push({a, b});
                        grid[a][b] = 2;
                    }
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return timer == 0 ? timer : timer-1;
    }
};