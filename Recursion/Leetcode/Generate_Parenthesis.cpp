class Solution {
public:

    void Parenthesis(int open, int close, vector<string>&ans, string &temp){
        // base case
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if(open > close)
        return;

        if(open){
            temp.push_back('(');
            Parenthesis(open-1, close, ans, temp);
            temp.pop_back();
        }
        if(close){
            temp.push_back(')');
            Parenthesis(open, close-1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;

        Parenthesis(n, n, ans, temp);
        return ans;
    }
};