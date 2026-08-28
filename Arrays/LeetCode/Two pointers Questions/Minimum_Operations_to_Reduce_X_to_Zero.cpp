class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // we will store value and key 
        unordered_map<int, int>mp;
        int sum = 0;

        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum +=  nums[i];
            mp[sum] = i; // we store value and key here
        }

        // edge case
        if(sum < x)
        return -1;

        int remainingSum = sum-x;
        int longestSubarray = INT_MIN;

        // reassign sum 
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];

            int findSum = sum - remainingSum;

            if(mp.find(findSum) != mp.end()){
                // this will give me the index of that sum
                int idx = mp[findSum];
                longestSubarray = max(longestSubarray, i-idx);
            }
        }

        return longestSubarray == INT_MIN ? -1 : n-longestSubarray;

    }
};