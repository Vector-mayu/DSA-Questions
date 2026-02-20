class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        int TargetSum = 0;
        
        for(int i=0; i<n; i++){
            sum+= arr[i];
        }
        
        if(sum % 2 == 0){
            TargetSum += arr[0];
            for(int i=1; i<n; i++){
                if(sum - TargetSum == sum/2)
                return true;
                TargetSum += arr[i];
            }
        }
        
        return false;
        
    }
};