
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int start = 0, end = 1;
        
        
        while(end < n){
            if(start == end){
                end++;
                continue;
            }
            
            
            int sum = arr[end] - arr[start];
            
            if(sum == x)
            return true;
            else if(sum > x)
            start++;
            else
            end++;
        }
        return false;
    }
};
