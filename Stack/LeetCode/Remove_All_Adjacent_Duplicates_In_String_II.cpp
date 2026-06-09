class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>>st;
        
        // we will keep count of that alphabet and push it once 
        for(int i=0; i<n; i++){
            // if stack is empty or stacks tops alphabet is not same as s[i] 
            // that means its coming for first time
            if(st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            }
            // check for those who have already came once
            else {
                st.top().second++;

                if(st.top().second == k){
                    st.pop();
                }
            }
        }

        // we will make the remaining string 
        string result = "";
        while(!st.empty()){
            if(st.top().second){
                result += st.top().first;
                st.top().second--;
            }
            else
            st.pop();
        }

        // as its stack we need to reverse the string
        reverse(result.begin(), result.end());

        return result;
    }
};