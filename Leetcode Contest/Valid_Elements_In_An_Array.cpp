class Solution {
public:

    bool checkLeft(vector<int>&nums, int i){
        for(int j=0; j<i; j++){
            if(nums[j] >= nums[i])
                return false;
        }
        return true;
    }

    bool checkRight(vector<int>&nums, int i){
        int n = nums.size();
        for(int j=n-1; j>i; j--){
            if(nums[j] >= nums[i])
                return false;
        }
        return true;
    }
    
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);

        if(n <= 1)
            return nums;

        for(int i=1; i<n-1; i++){
            if(checkLeft(nums, i) || checkRight(nums, i))
                ans.push_back(nums[i]);
        }
        ans.push_back(nums[n-1]);

        return ans;
    }
};