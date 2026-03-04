class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], curr = nums[0];

        if(n == 1)
        return nums[0];

        for(int i=1; i<n; i++){
            int temp = curr + nums[i];
            if(temp > nums[i]){
                curr = temp;
                ans = max(ans, curr);
            }
            else{
                curr = nums[i];
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};