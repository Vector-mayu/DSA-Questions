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