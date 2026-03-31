class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();

        int prefix = 0, suffix = 1;
        vector<int>LPS(n,0);

        // We build LPS for Needle
        while(suffix < n){
            if(needle[prefix] == needle[suffix]){
                LPS[suffix] = prefix+1;
                prefix++, suffix++;
            }
            else{
                if(prefix == 0)
                suffix++;
                else
                prefix = LPS[prefix -1];
            }
        }

        prefix = 0, suffix =0;

        // Check with the string now
        while(suffix<m && prefix<n){
            if(haystack[suffix] == needle[prefix])
            suffix++, prefix++;
            else
            if(prefix == 0)
            suffix++;
            else
            prefix = LPS[prefix - 1];
        }

        if(prefix == n)
        return suffix - prefix;

        return -1;
    }
};