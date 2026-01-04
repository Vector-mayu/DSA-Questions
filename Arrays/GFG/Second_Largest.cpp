class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        int total = 0;
        
        for(int i=0; i<n; i++)
        {
           sum = max(arr[i], sum);
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] != sum)
            total = max(arr[i], total);
        }
        
        return total;
    }
};