// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string &s) {
        // code here
        stack<int>st;
        int n = s.size();
        int num = 0;
        
        vector<int>ans;
        
        for(char ch : s) {
            if(ch == '(') {
                st.push(++num);
                ans.push_back(num);
            }
            else if(ch == ')') {
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        return ans;
    }
};