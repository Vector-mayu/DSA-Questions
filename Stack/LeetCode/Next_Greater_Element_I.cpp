class Solution {
public:

    int nextGreater(vector<int>&nums, int element){
        int index = -1;
        for(int i=0; i<nums.size(); i++){
            if(element == nums[i]){
                index = i;
                break;
            }
        }
        if(index >= nums.size())
        return -1;

        int greater;
        for(int i=index+1; i<nums.size(); i++){
            if(nums[index] < nums[i]){
                return nums[i];
            }
        }
        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        for(int i=0; i<nums1.size(); i++){
            int greater = nextGreater(nums2, nums1[i]);
            ans.push_back(greater);
        }

        return ans;
    }
};