// Expected TC: O(Log(n*m));
// Outer Loop = Log n
// Inner Loop = Log m
// Total TC = Logn * logm => O(Log(n*m))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // row size
        int m = matrix[0].size(); // column size
        int start = 0, end = n-1;

        if(n == 1){
            if(matrix[0][0] == target)
            return true;
        } 

        while(start <= end){
            int mid = start + (end - start)/2;

            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                int left = 0, right = m-1;
                while(left <= right){
                    int midCol = left + (right - left)/2;

                    if(matrix[mid][midCol] == target)
                    return true;
                    else if(matrix[mid][midCol] > target)
                    right = midCol - 1;
                    else
                    left = midCol + 1;
                }
                return false;
            }
            else if(matrix[mid][0] > target)
            end = mid - 1;
            else
            start = mid + 1;
        }
        return false;
    }
};