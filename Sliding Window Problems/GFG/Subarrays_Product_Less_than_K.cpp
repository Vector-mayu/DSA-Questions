class Solution {
  public:
    int countSubarray(vector<int>& arr, int k) {
        // code here
        
        // Write your code here.
        // base case
        if(k <= 1)
        return 0;

        int left = 0, right = 0;
        int count = 0, n = arr.size();
        long long product = 1;

        while(right < n){
            product *= arr[right];

            while(product >= k){
                product /= arr[left];
                left++;
            }

            count += (right - left + 1);
            right++;
        }

        return count;
        
    }
};