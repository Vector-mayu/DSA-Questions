class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int count = 0;
        long long sum = 0;
        int minLength = INT_MAX;

        while(right < n){
            sum += nums[right];

            while(sum >= target){
                minLength = min(minLength, (right - left + 1));
                sum -= nums[left];
                left++;
            }

            right++;
        }

        if(minLength == INT_MAX)
        return 0;

        return minLength;
    }
};