class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int left = 0, right = k*2, n = nums.size();
        vector<int>ans(n, -1);
        long long sum = 0;
        
        if(n < k*2+1)
        return ans;
        for(int i = 0; i<=k*2; i++){
            sum += nums[i];
        }

        while(right < n){
            int avg = sum/(k*2+1);
            ans[(left+right)/2] = avg;
            sum -= nums[left];
            left++;
            right++;
            if(right < n){
                sum += nums[right];
            }
        }

        return ans;
    }
};