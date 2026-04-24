class Solution {
public:

    void countSubset(vector<int>&arr, int i, int n, int sum, int &count, int target){
        // this if block must come before base case
        if(target == sum){
            count++;
            return;
        }
        // base case
        if(sum > target || i == n)
        return; 

        // left side take the integer
        countSubset(arr, i+1, n, sum+arr[i], count, target);
        //right side dont take integer
        countSubset(arr, i+1, n, sum, count, target);
    }

    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here
        int count = 0;
        countSubset(arr, 0, arr.size(), 0, count, target);

        return count;
    }
};