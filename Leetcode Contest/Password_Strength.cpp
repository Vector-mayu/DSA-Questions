class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        unordered_set<char>st;

        for(int i=0; i<password.length(); i++){
            char ch = password[i];

            if(st.count(ch)){
                continue;
            }
            
            if(ch >= 'a' && ch <= 'z'){
                strength += 1;
                st.insert(ch);
            }
            else if(ch >= 'A' && ch <= 'Z'){
                strength += 2;
                st.insert(ch);
            }
            else if(ch >= '0' && ch <= '9'){
                strength += 3;
                st.insert(ch);
            }
            else{
                strength += 5;
                st.insert(ch);
            } 
        }

        return strength;
    }
};