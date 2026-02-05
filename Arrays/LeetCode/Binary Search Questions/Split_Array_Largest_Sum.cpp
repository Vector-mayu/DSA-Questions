class Solution {
public:

    bool SplitArrayPossible(vector<int>&arr, int maxSum, int k){
        int count = 1, sum = arr[0];

        for(int i=1; i<arr.size(); i++){
            sum += arr[i];
            if(sum > maxSum){
                count++;
                sum = arr[i];
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int end = 0, ans = 0;
        int start = *max_element(nums.begin(), nums.end());

        if(k > n)
        return -1;

        for(int i=0; i<n; i++){
            end += nums[i];
        }

        while(start <= end){
            int mid = start + (end - start)/2;

            if(SplitArrayPossible(nums, mid, k)){
                ans = mid;
                end = mid -1;
            }
            else
            start = mid +1;
        }
        return ans;
    }
};