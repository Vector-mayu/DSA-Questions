// Brute Force Approach 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i=0; i<n; i++){
            vector<bool>visited(95,0);
            int count = 0;
            for(int j=i; j<n; j++){
                if(visited[s[j] - 32])
                break;
                visited[s[j] - 32] = 1;
                count++;
            }
            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};

// Optimization with Sliding Window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        bool freq[256] = {0};
        int start = 0, end = 0;
        int maxLen = 0;

        while(end < n){
            // Mark Freq vector as 0 untill there are duplicate chars in that window
            // keep all unqiue chars in that window
            // jab tak woh repeated char 0 na hoga tabh taak sabhko 0 karte jao
            while(freq[s[end]]){
                freq[s[start]] = 0;
                start++;
            }

            // abh sabh unqiue chars he bache as we already aplied while loop to eliminate repeated chars
            freq[s[end]] = 1;
            end++;

            maxLen = max(maxLen, (end - start));
        }

        return maxLen;
    }
};