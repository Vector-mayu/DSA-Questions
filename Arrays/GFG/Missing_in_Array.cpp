class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        // this is XOR approach 
        // if 4^3^4 = 3 (^ = XOR operation)
        
        int ans = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            ans = ans^arr[i];
        }
        
        for(int i=1; i<=n+1; i++){
            ans = ans^i;
        }
        
        return ans;
    }
};