class Solution {
public:
    string sortSentence(string s) {
        vector<string>temp(10);
        string str = "";

        for(int i=0; i<s.length(); i++){
            if(s[i] != ' ')
            str.push_back(s[i]);
            if(s[i] == ' ' || i == s.length() - 1){
                char last = str.back();
                int pos = last - '0';
                str.pop_back();
                temp[pos-1] = str;
                str = "";
            }
        }

        string ans = "";
        for(int i=0; i<temp.size(); i++){
            if(temp[i] == "")
            break;
            ans+= temp[i] + " ";
        }

        ans.pop_back();

        return ans;
    }
};