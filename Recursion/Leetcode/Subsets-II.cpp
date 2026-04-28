// Brute Force Aproach TC = O(4^n) 

class Solution {
public:

    void countSubset(vector<int>&arr, int i, int n, vector<vector<int>>&ans, vector<int>&temp){
        if(n == i){
            if(find(ans.begin(), ans.end(), temp) == ans.end())
            ans.push_back(temp);
            return;
        }
            // take element 
            temp.push_back(arr[i]);
            countSubset(arr, i+1, n, ans, temp);

            // dont take
            temp.pop_back();
            countSubset(arr, i+1, n, ans, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        
        countSubset(nums, 0, nums.size(), ans, temp);

        return ans;
    }
};