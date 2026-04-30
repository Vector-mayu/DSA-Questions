// TC :- O(2^n)

class Solution {
public:

    void solve(vector<int>&arr, int index, vector<vector<int>>&ans, vector<int>&temp, int target){
        // if value goes in -ve while subtracting arr[i] from target
        if(target < 0)
        return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<arr.size(); i++){
            if(i > index && arr[i] == arr[i-1]){
                continue;
            }

            temp.push_back(arr[i]); // DO
            solve(arr, i+1, ans, temp, target-arr[i]); // Explore
            temp.pop_back(); // UNDO

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, ans, temp, target);
        return ans;
    }
};