class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>count(256, 0);

        for(int i=0; i<s.length(); i++){
            count[s[i]]++;
        }

        int ans = 0;
        for(int i=0; i<256; i++){
            if(count[i]){
                if(count[i] % 2 == 0) // even
                ans += count[i];
                else
                ans += count[i]-1; // odd
            }
        }

        if(ans < s.length())
        return ans+1;

        return ans;
    }
};