class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0;
        vector<vector<int>>temp;
        vector<vector<int>>mat1;
        temp = mat;
        mat1 = mat;
        

        while(k){
            while(row < n){
                // Left shift
                if(row % 2 == 0){
                    for(int j=m-1; j>=0; j--){
                        mat[row][j] = temp[row][(j - 1 + m) % m];
                    }
                    row++;
                }
                // Right shift 
                if(row < n){
                    if(row % 2 == 1){
                        for(int j=0; j<m; j++){
                            mat[row][(j+1)%m] = temp[row][j];;
                        }
                        row++;
                    }
                }
            }
            temp = mat;
            row = 0;
            k--;
        }

        if(mat == mat1)
        return 1;

        return 0;
    }
};