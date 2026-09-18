class Solution {
public:

    bool isValid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();

        // if src and dest both are same
        int X = N-1, Y = M-1;
        if(X==0 && Y==0){
            return grid[0][0] == 0 ? 1 : -1;
        }
        

        // if src or dest any of them is 0
        if(grid[0][0] == 1 || grid[X][Y] == 1){
            return -1;
        }

        queue<pair<int, int>>q;
        q.push({0, 0});

        // mark 0,0 as visited to avoid further repeatation
        // instead of an extra vector we will make it 0 so that we wont visit
        grid[0][0] = 1;

        int totalDist = 0;
        while(!q.empty()){
            int size = q.size();
            totalDist++;

            int row[8] = {1, -1, 0, 0, 1, -1, 1, -1};
            int col[8] = {0, 0, 1, -1, 1, 1, -1, -1};

            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k=0; k<8; k++){
                    int a = i + row[k], b = j + col[k];

                    if(isValid(a, b, N, M) && grid[a][b] == 0){
                        // check if we reach destination
                        if(a == X && b == Y){
                            return totalDist + 1;
                        }

                        q.push({a, b});
                        grid[a][b] = 1;
                    }
                }
            }
        }

        return -1;
    }
};