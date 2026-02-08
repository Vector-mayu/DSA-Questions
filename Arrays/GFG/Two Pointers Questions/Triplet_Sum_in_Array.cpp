// Time Complexity :- O(n^2)

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-2; i++){
            int start = i+1, end = n-1;
            int newTarget = target - arr[i];
            
            while(start < end){
                int sum = arr[start] + arr[end];
                
                if(sum == newTarget)
                return true;
                
                else if(sum > newTarget)
                end--;
                
                else
                start++;
            }
        }
        return false;
    }
};