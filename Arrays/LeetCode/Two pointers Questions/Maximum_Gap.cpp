class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        return 0;

        sort(nums.begin(), nums.end());

        int first, second;
        int ans=0;

        for(int i=0; i<n-1; i++){
            first = nums[i];
            second = nums[i+1];

            ans = max(ans, second - first);        
        }
        return ans;
    }
};