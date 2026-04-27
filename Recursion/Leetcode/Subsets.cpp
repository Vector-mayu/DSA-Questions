// TC = O(2*n)
// SC = O(n * 2*n) n is depth and 2*n are total elements

class Solution {
public:

    void countSubset(vector<int>&arr, int i, int n, vector<vector<int>>&ans, vector<int>&temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        // left call add it 
        temp.push_back(arr[i]);
        countSubset(arr, i+1, n, ans, temp);
        // right call dont add it
        temp.pop_back();
        countSubset(arr, i+1, n, ans, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        countSubset(nums, 0, nums.size(), ans, temp);
        return ans;
    }
};