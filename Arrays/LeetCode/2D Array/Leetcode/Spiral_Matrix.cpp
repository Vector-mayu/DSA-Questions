class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int rowStart = 0, rowEnd = n-1;
        int colStart = 0, colEnd = m-1;

        vector<int>ans;

        while(rowStart <= rowEnd && colStart <= colEnd){
            // 1. Print ColStart -> ColEnd Accending Order [L->R]
            for(int i=colStart; i<=colEnd; i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            // 2. Print RowStart -> RowEnd Accending Order [top -> bottom]
            for(int i=rowStart; i<=rowEnd; i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            // 3. Print ColEnd -> ColStart Decending Order [R->L]
            // Check for Edge Case [row]
            if(rowStart <= rowEnd){ // Edge Case Checking
                for(int i=colEnd; i>=colStart; i--){
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            // 4. Print RowEnd -> RowStart Decending Order [bottom -> top]
            // Check for Edge Case [col]
            if(colStart <= colEnd){
                for(int i=rowEnd; i>= rowStart; i--){
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }

        return ans;
    }
};