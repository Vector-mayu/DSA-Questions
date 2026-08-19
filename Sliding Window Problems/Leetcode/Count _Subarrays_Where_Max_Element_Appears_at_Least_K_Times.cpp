class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxValue = nums[0];

        for(int x : nums){
            maxValue = max(maxValue, x);
        }

        int maxValueCount = 0, left = 0, right = 0, n = nums.size();
        long long result = 0;

        while(right < n){
            if(nums[right] == maxValue){
                maxValueCount++; 
            }

            while(maxValueCount >= k){
                result += (n - right);

                if(maxValue == nums[left]){
                    maxValueCount--;
                }
                left++;
            }
            right++;
        }

        return result;
    }
};