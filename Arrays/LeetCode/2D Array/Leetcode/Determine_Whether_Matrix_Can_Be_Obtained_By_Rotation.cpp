class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for(int r=1; r<=4; r++){
            // Transpose
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
                }
            }

            // Reverse Rows
            for(int i=0; i<n; i++){
                reverse(mat[i].begin(), mat[i].end());
            }
            
            // Check for match condition
            if(mat == target)
            return true;
        }

        return false;
    }
};