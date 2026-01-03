// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size()-1;
        int temp = arr[n];
        
        for(int i=n-1; i>=0; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[0] = temp;
        
        // Store the last number
        // Iterate from arr[n-2] (second last position)
        // shift the positions in clockweise direction 
        // after iterating from n-2 -> 0 push last element in arr[0]
        // thats all we need
    }
};