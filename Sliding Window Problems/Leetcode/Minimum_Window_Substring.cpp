// Approach 1 -> unordered_map 
// less efficieint beacuse we need to find that element int freq repeatdly
// finding any element in map is O(N) time

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        if(n < m)
            return "";

        int left = 0, right = 0;

        unordered_map<char, int> freq;
        unordered_map<char, int> temp;

        // Store required frequency of each character
        for(int i = 0; i < m; i++) {
            freq[t[i]]++;
        }

        pair<int, int> range = {-1, -1};
        int minRange = INT_MAX;

        // Number of required characters whose
        // required frequency is completely satisfied
        int distinct = 0;

        while(right < n) {

            // Add right character
            char c = s[right];
            temp[c]++;

            // Character requirement is satisfied
            if(freq.count(c) && temp[c] == freq[c]) {
                distinct++;
            }

            // Current window contains all required characters
            while(distinct == freq.size()) {

                // Update minimum window
                if(right - left + 1 < minRange) {
                    minRange = right - left + 1;
                    range.first = left;
                    range.second = right;
                }

                // Remove left character
                char c = s[left];
                temp[c]--;

                // Requirement is no longer satisfied
                if(freq.count(c) && temp[c] < freq[c]) {
                    distinct--;
                }

                left++;
            }

            right++;
        }

        // No valid window found
        if(range.first == -1)
            return "";

        return s.substr(range.first, minRange);
    }
};