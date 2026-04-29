class Solution {
public:

    void countPermutation(vector<int>&arr, int index, int n, vector<vector<int>>&ans){
        // push case (base case)
        if(index == n-1){
            ans.push_back(arr);
            return;
        }

        for(int i=index; i<n; i++){
            swap(arr[i], arr[index]);
            countPermutation(arr, index+1, n, ans);
            swap(arr[i], arr[index]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        countPermutation(nums, 0, nums.size(), ans);
        return ans;
    }
};