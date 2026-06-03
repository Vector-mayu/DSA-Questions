class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        int n = s.size(), m = t.size();

        for(int i=0; i<n; i++){
            if(st.empty()){
                if(s[i] != '#'){
                    st.push(s[i]);
                }
            }
            else if(st.top() != '#' && s[i] == '#'){
                st.pop();
            }
            else{
                if(s[i] != '#'){
                    st.push(s[i]);
                }
            }
        }

        s = "";
        while(!st.empty()){
            s+= st.top();
            st.pop();
        }

        for(int i=0; i<m; i++){
            if(st.empty()){
                if(t[i] != '#'){
                    st.push(t[i]);
                }
            }
            else if(st.top() != '#' && t[i] == '#'){
                st.pop();
            }
            else{
                if(t[i] != '#'){
                    st.push(t[i]);
                }
            }
        }

        t = "";
        while(!st.empty()){
            t+= st.top();
            st.pop();
        }

        return s == t ? true : false;
    }
};