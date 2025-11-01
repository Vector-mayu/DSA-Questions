//                  GFG Medium Level Problem
//                  Companies : Amazon Samsung Accolite

class Solution {
  public:
  
    int CalculateCount(vector<vector<int>> &mat, int mid, int n)
    {
        int count = 0;
        int row = n-1; // row starts with leftmost bottom element  
        int col = 0; // 1st element
        
        // if we get mat[r][c] lesser then increment col++;
        // if we get mat[r][c] greater then just decrement row--
        while(row >=0 && col < n)
        {
            if(mat[row][col] <= mid) // lesser cond
            {
                // update count eg: row = 3 then count += row(3) + 1 = 4 total 4 elements
                count += (row + 1);
                col++; 
            }
            else 
            {
                row--;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        
        int start = mat[0][0]; // start with 1st element of matrix
        int end = mat[n-1][n-1]; // The last element of matrix
        
        while(start < end)
        {
            int mid = start + (end - start)/2; // mid formula
            int count = CalculateCount(mat, mid, n); // this function calculates total counts of
            // Elements possible between that range of start -- end
            
            if(count < k)// if count is lesser then we need more elements to check so we should go right
            {
                start = mid + 1; // go right (mid <-> end)
            }
            else // if count is more then we need less to check so we should go left
            {
                end = mid; // go left (start <--> mid)
            }
        }
        
        return start; // start will contain the exact value where it lied and stopped 
    }
};
