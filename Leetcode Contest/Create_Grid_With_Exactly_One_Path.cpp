class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n, '#'));

        int i = 0;
        for(int j=0; j<n; j++){
            grid[i][j] = '.';
        }

        int j = n-1;
        for(int i = 0; i<m; i++){
            grid[i][j] = '.';
        }

        vector<string>ans(m);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i] += grid[i][j];
            }
        }

        return ans;
    }
};