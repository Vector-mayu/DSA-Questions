class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.length(); i++){
            if(s[i] <= 'Z' && s[i] >= 'A'){
                int diff = s[i] - 'A';
                s[i] = 'a' + diff;
            }
        }
        return s;
    }
};