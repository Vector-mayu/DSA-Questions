class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
        return false;
        
        int n = s.length();
        for(int i=0; i<n; i++){
            int flag = true;
            for(int j=0; j<n; j++){
                if(s[j] != goal[(j+i)%n])
                flag = false;
            }
            if(flag)
            return true;
       }

       return false;
    }
};