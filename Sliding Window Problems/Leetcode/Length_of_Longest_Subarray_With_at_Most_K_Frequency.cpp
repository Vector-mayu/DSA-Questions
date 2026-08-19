class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxLength = INT_MIN;

        unordered_map<int, int>count;

        while(right < n){
            if(count[nums[right]] >= k){
                while(nums[left] != nums[right]){
                    count[nums[left]]--;
                    left++;
                }
                count[nums[left]]--;
                left++;
            }

            count[nums[right]]++;
            right++;
            maxLength = max(maxLength, (right - left));
        }

        return maxLength;
    }
};    