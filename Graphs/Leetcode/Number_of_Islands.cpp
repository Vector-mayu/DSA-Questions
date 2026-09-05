TC :- O(N x M)
SC :- Recursive Tree O(N x M)

class Solution {
public:

    bool isValid(int i, int j, int r, int c){
        return i>=0 && j>=0 && i<r && j<c;
    }

    void DFS(vector<vector<char>>&grid, int i, int j, int r, int c){
        // we will mark 1(land) as 0(water) just to denote that we have already visited this part
        grid[i][j] = '0';

        int row[4] = {0, 0, 1, -1};
        int col[4] = {1, -1, 0, 0};

        for(int k=0; k<4; k++){
            int a = i + row[k], b = j + col[k];

            if(isValid(a, b, r, c) && grid[a][b] == '1'){
                DFS(grid, a, b, r, c);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int totalNumberofIslands = 0;
        int r = grid.size();
        int c = grid[0].size();

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1'){
                    totalNumberofIslands++;
                    DFS(grid, i, j, r, c);
                }
            }
        }

        return totalNumberofIslands;
    }
};