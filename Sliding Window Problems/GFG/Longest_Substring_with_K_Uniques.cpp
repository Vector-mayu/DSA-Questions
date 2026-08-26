// Pattern :- Longest + EXACTLY K distinct
// we need the longest string but with exactly k distinct chars in it

// FLOW

// Expand
//   ↓
// Add character
//   ↓
// distinct > k ?
//   ↓ YES
// Shrink
//   ↓
// distinct <= k
//   ↓
// distinct == k ?
//   ↓ YES
// Update maxLength

// IDEA

Longest substring
        +
Exactly K distinct
        ↓
Maintain At Most K
        +
Only update when Exactly K

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size(), left = 0, right = 0, maxLength = INT_MIN;
        int distinct = 0;
        
        unordered_map<char, int>freq;
        
        while(right < n){
            char c = s[right];
            
            freq[c]++;
            
            if(freq[c] == 1){
                distinct++;
            }
            
            // if the size of window gets greater than k (distinct > k)
            while(distinct > k){
                char a = s[left];
                
                if(freq[a] == 1){
                    distinct--;
                }
                
                freq[a]--;
                
                left++;
            }
            
            if(distinct == k)
            maxLength = max(maxLength, right - left + 1);
            
            right++;
        }
        
        return maxLength == INT_MIN ? -1 : maxLength;
    }
};