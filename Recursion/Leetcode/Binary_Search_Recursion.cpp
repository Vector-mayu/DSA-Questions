class Solution {
public:

    int BinarySearch(vector<int>&nums, int start, int end, int target){
        // base case
        if(start > end)
        return -1;

        // calculate mid
        int mid = start + (end - start)/2;

        // match condition
        if(nums[mid] == target)
        return mid;

        // Left condition condition
        else if(nums[mid] > target)
        return BinarySearch(nums, start, mid - 1, target);
      
        // Right Condition
        else
        return BinarySearch(nums, mid+1, end, target);
    }

    int search(vector<int>& nums, int target) {
        return BinarySearch(nums, 0, nums.size()-1, target);
    }
};