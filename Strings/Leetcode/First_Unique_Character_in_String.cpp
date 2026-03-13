class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};

        for(int i=0; i<s.length(); i++){
            int index = s[i] - 'a';
            count[index]++;
        }

        for(int i=0; i<s.length(); i++){
            if(count[s[i] -'a'] == 1)
            return i; 
        }

        return -1;
    }
};