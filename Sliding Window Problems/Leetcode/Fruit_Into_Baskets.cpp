// 904. Fruit Into Baskets
// Indirect Sliding window problem 

// key idea is 
// right → expand window

// if distinct > 2
//         ↓
//     shrink from left
//         ↓
// until distinct <= 2

// then:
// maxSize = max(maxSize, window_size)

// AtMost(k) type problem

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // we just need to calculate the largest size 
        int n  = fruits.size();
        int left = 0, right = 0, count = 0, maxSize = INT_MIN;

        unordered_map<int, int>freq;

        while(right < n){
            freq[fruits[right]]++;

            if(freq[fruits[right]] == 1){
                count++;
            }

            while(count > 2){
                if(freq[fruits[left]] == 1){
                    count--;
                }

                freq[fruits[left]]--;
                left++;
            }
            
            maxSize = max(maxSize, right - left + 1);

            right++;
        }

        return maxSize;
    }
};