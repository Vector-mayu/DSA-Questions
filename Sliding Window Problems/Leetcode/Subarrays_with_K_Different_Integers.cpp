/*
We need subarrays with EXACTLY k distinct integers.

Finding exact k directly is tricky, so use:
    Exactly(k) = AtLeast(k) - AtLeast(k + 1)

Why?
- AtLeast(k) counts subarrays having k or more distinct integers.
- AtLeast(k + 1) removes subarrays having k + 1 or more.
- What remains = exactly k distinct integers.

How atLeastK works:
- Keep a sliding window and count distinct integers.
- When the window has at least k distinct integers, every extension
  of this window to the right will also have at least k distinct integers.
- So we add (n - right) possible subarrays.
- Then move left forward to find other valid windows.
*/

class Solution {
public:

    // Counts subarrays having AT LEAST k distinct integers
    int atleastK(vector<int>& nums, int left, int right, int n, int k) {

        unordered_map<int, int> freq;

        int count = 0;  // number of distinct integers
        int total = 0;  // total valid subarrays

        while(right < n) {

            // Add current element to the window
            freq[nums[right]]++;

            // First occurrence -> new distinct integer
            if(freq[nums[right]] == 1) {
                count++;
            }

            // Window has at least k distinct integers
            while(count >= k) {

                // [left...right], [left...right+1], ...
                // are all valid -> (n - right) subarrays
                total += n - right;

                // Remove left element and shrink window
                freq[nums[left]]--;

                // This integer is completely removed
                if(freq[nums[left]] == 0) {
                    count--;
                }

                left++;
            }

            right++;
        }

        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int n = nums.size();

        // Exactly(k) = AtLeast(k) - AtLeast(k + 1)
        return atleastK(nums, 0, 0, n, k)
             - atleastK(nums, 0, 0, n, k + 1);
    }
};