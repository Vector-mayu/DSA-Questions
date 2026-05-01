// TC :- O(n! × n) (n! = total permutation, n = work done to push in string)
// SC :- O(n! × n) (n! = stored in ans, n = unordered_set)


class Solution {
  public:
  
    void solve(string &s, int index, int n, vector<string>&ans, unordered_set<string>&st){
        // base case
        if(index == n-1){
            if(!st.count(s)){
                ans.push_back(s);
                st.insert(s);
            }
            return;
        }
        
        // lets solve 
        for(int i=index; i<n; i++){
            // permutation logic
            swap(s[i], s[index]);
            solve(s, index+1, n, ans, st);
            swap(s[i], s[index]);
        }
    }
  
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string>ans;
        unordered_set<string>st;
        solve(s, 0, s.size(), ans, st);
        return ans;
    }
};
