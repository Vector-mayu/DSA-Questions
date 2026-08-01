class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        
        // we will sort them according to end time
        sort(arr.begin(), arr.end(), 
            [] (const vector<int>&a, const vector<int>&b){
                return a[1] < b[1];
            }
        );
        
        // store prev end time
        int prevEndTime = arr[0][1];
        int count = 1;
        
        for(int i=1; i<n; i++){
            if(prevEndTime <= arr[i][0]){
                count++;
                prevEndTime = arr[i][1];
            }
        }
        
        if(n-count == 0)
        return true;
        
        return false;
    }
};