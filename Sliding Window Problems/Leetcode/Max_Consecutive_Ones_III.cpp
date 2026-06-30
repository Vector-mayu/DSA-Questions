class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zero = 0;
        int maxLen = 0, l = 0, r = 0;

        while(r < n){
            // if we get any zero just flip it and inc zero count
            if(nums[r] == 0){
                zero++;
            }
            // we will shift the left to right untill and unless we reach the next zero
            while(zero > k){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            // executes all time when there are k or less than k zeros in the window
            if(zero <= k){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            }

            // VERY IMPORTANT always inc right after each operation
            r++;
        } 

        return maxLen;
    }
};