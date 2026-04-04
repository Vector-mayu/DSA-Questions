class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        int n = txt.size();
        int m = pat.size();
        
        vector<int>LPS(m,0);
        
        // find the LPS of PAT
        int prefix = 0, suffix = 1;
        
        while(suffix < m){
            if(pat[prefix] == pat[suffix]){
                LPS[suffix] = prefix + 1;
                prefix++, suffix++;
            }
            else{
                if(prefix == 0){
                    suffix++;
                }
                else{
                    prefix = LPS[prefix-1];
                }  
            }
        }
        
        // now lets find the total occurances of pat string
        vector<int>ans;
        
        prefix = 0, suffix = 0;
        
        while(suffix < n){
            if(pat[prefix] == txt[suffix]){
                if(prefix == m-1){
                    ans.push_back(suffix - (m - 1));
                    prefix = LPS[prefix], suffix++;
                    continue;
                }
                prefix++, suffix++;
            }
            else{
                if(prefix == 0){
                    suffix++;
                }
                else{
                    prefix = LPS[prefix-1];
                }  
            }
        }
        
        return ans;
        
        
    }
};