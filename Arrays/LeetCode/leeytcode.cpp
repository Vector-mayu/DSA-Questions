class Solution {
public:

    int BinarySearch(int start, int end, vector<int>nums, int target){
        int index = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target)
            return mid;
            else if(nums[mid] < target)
            start = mid +1;
            else
            end = mid -1;
        }
        return -1;
    }

    int findPivot(vector<int>&arr, int n){
        int start = 0, end = n-1;

        while(start < end){
            int mid = start + (end-start)/2;

            if(arr[mid] > arr[end])
            start = mid +1;
            else
            end = mid;
        }
        return end;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums,n);

        int index = BinarySearch(0, pivot-1, nums, target);

        if(index != -1)
        return index;

        index = BinarySearch(pivot, n-1, nums, target);

        return index;
    }
};