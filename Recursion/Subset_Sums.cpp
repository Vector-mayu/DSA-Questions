class Solution {
public:

    void countSubset(vector<int>arr, int i, int n, int sum, vector<int>&ans){
        // base case 
        if(i == n){
            ans.push_back(sum);
            return;
        }
        
        // take that value into sum -> adding case
        countSubset(arr, i+1, n, sum+arr[i], ans);
        // dont take that value into sum 
        countSubset(arr, i+1, n, sum, ans);
    }

    vector<int> subsetSums(vector<int>& arr) {
        // Your code here
        vector<int>ans;
        countSubset(arr, 0, arr.size(), 0, ans);
        return ans;
    }
};