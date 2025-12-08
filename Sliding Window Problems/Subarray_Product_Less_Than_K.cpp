class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int start = 0, end = 0;
        int n = nums.size();
        int product = 1;
        int count = 0;

        while(end < n)
        {
          product*= nums[end];

          // agar product bada hua mere k se and start end se bada na ho
          while(product >= k && start <= end)
          {
              product /= nums[start]; // shift ahead
              start++;
          }

          count+= 1 + (end-start); // if we have start 0 and end 2 then count [1 + (2-0)] = 3
          end++;
        }

        return count;
        
    }
};