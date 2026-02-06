class Solution {
  public:
  
    bool CowAllocationPossible(vector<int>arr, int maxDistance, int k){
        int count = 1, distance = arr[0];
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] - distance >= maxDistance){
                count++;
                distance = arr[i];
            }
        }
        
        return count >= k;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size(), start=0, end, ans;
        sort(stalls.begin(), stalls.end()); 
        
        end = stalls[n-1]-stalls[0];
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(CowAllocationPossible(stalls, mid, k)){
                ans = mid;
                start = mid + 1; // Shift Right Side cuz we want maximum value
            }
            else
            end = mid - 1;
        }
        return ans;
    }
};