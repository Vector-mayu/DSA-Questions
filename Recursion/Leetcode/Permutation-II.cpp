// TC :- O(n!) + O(n logn) + O(n log n) 1. Permutation, 2. Count(comparison + all nodes visited), 3. set insert(compare + find corrrect position) 
// SC :- O(n) + O(n! x n) + O(n! x n) 1. Stack space 2. ans 3. set
//

class Solution {
public:

    void solve(vector<int>&arr, int index, int n, vector<vector<int>>&ans, set<vector<int>>&st){
        if(index == n-1){
            if(!st.count(arr)){
                ans.push_back(arr);
                st.insert(arr);
            }
            return;
        }

        for(int i=index; i<n; i++){
            // Permutation logic
            swap(arr[i], arr[index]);
            solve(arr, index+1, n, ans, st);
            swap(arr[i], arr[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        solve(nums, 0, nums.size(), ans, st);
        return ans;
    }
};