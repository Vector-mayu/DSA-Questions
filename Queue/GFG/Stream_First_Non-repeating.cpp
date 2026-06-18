class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n = s.size();
        queue<char>q;
        vector<int>freq(26, 0);
        
        string ans = "";
        for(int i=0; i<n; i++){
            // any number comes just push it
            freq[s[i] - 'a']++;
            q.push(s[i]);
            
            // now we will pop the numbers untill we dont have any repeating chars
            while(!q.empty() && freq[q.front() -'a'] > 1){
                q.pop();
            }
            
            // if queue empty then push #
            if(q.empty()){
                ans += '#';
            }
            // if q.empty means we have a non repeating char in front
            else{
                ans += q.front();
            }
        }
        
        return ans;
    }
};