// TC :- O(NlogN)

class Solution {
public:

    void Merge(vector<int>&arr, int start, int mid, int end){
        // create a temporary array
        vector<int>temp(end-start+1);
        int left = start, right = mid + 1;

        // comparison loop
        int index = 0;
        while(left <= mid && right <= end){
            // if left is smaller
            if(arr[left] <= arr[right])
            temp[index++] = arr[left++];
            // if right is smaller
            else
            temp[index++] = arr[right++];
        }

        // remaining on left side
        while(left <= mid)
        temp[index++] = arr[left++];
        // remaining on right side
        while(right <= end)
        temp[index++] = arr[right++];

        // copy temp array into actual array
        index = 0;
        for(int i=start; i<=end; i++)
        arr[i] = temp[index++];
    }

    void MergeSort(vector<int>&arr, int start, int end){
        // base case
        if(start >= end)
        return;

        // mid calculation
        int mid = start + (end - start)/2;
        // left conditon 
        MergeSort(arr, start, mid);
        // right condition
        MergeSort(arr, mid+1, end);
        // Merge Them
        Merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};