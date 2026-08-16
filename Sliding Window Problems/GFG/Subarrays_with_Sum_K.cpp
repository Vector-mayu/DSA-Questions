class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int prefixSum = 0;
        int result = 0;
        
        unordered_map<int, int>count;
        count[0]=1;
        
        for(auto x : arr){
            prefixSum += x;
            
            result += count[prefixSum - k];
            count[prefixSum]++;
        }
        
        return result;
    }
};