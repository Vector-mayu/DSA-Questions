// Time Complexity :- O(n^2)

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        
        // 1st 90 Degree Rotation
        
        // Transpose the Matrix
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Column Reverse
        for(int j=0; j<n; j++){
            int top = 0, bottom = n-1;
            
            while(top < bottom){
                swap(mat[top][j], mat[bottom][j]);
                 top++;
                bottom--;
            }
        }
        
        // 2nd 90 Degree Rotation
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Column Reverse
        for(int j=0; j<n; j++){
            int top = 0, bottom = n-1;
            
            while(top < bottom){
                swap(mat[top][j], mat[bottom][j]);
                 top++;
                bottom--;
            }
        }
    }
};