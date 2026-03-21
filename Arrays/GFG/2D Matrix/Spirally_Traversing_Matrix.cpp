class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        
        int rowStart = 0, rowEnd = n-1;
        int colStart = 0, colEnd = m-1;
        
        while(rowStart <= rowEnd && colStart <= colEnd){
            
            // Horizontal col changes row remains same
            for(int i=colStart; i<=colEnd; i++){
                ans.push_back(mat[rowStart][i]);
            }
            rowStart++;
            
            // Vertical row changes col remains same
            for(int i=rowStart; i<=rowEnd; i++){
                ans.push_back(mat[i][colEnd]);
            }
            colEnd--;
            
            // Horizontal Reverse col Changes row remains same
            if(rowStart <= rowEnd){
                for(int i=colEnd; i >= colStart; i--){
                    ans.push_back(mat[rowEnd][i]);
                }
                rowEnd--;
            }
            
            // Vertical Reverse row changes col remains the same
            if(colStart <= colEnd){
                for(int i=rowEnd; i>= rowStart; i--){
                    ans.push_back(mat[i][colStart]);
                }
                colStart++;
            }
        }
        
        return ans;
    }
};