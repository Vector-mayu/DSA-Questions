class Solution {
public:

    void findCandidates(vector<int>&arr, int i, int n, int sum, vector<vector<int>>&ans, vector<int>&temp, int k){
        // push case
        if(sum == k){
            ans.push_back(temp);
            return;
        }
        //base case 
        if(sum > k || i==n)
        return;

        temp.push_back(arr[i]);
        findCandidates(arr, i, n, sum+arr[i], ans, temp, k);

        temp.pop_back();
        findCandidates(arr, i+1, n, sum, ans, temp, k);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        findCandidates(candidates, 0, candidates.size(), 0, ans, temp, target);
        return ans;
    }
};