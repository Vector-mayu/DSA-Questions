class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here
        int prefixSum = 0;
        int result = 0;
        unordered_map<int, int>count;
        // edge case -> initially push zero if arr[0] = 0
        count[0]++;
        
        for(int i=0; i<arr.size(); i++){
            prefixSum += arr[i];
            
            result += count[prefixSum]; // if not exist it return 0
            
            count[prefixSum]++;
        }
        
        return result;
        
    }
};