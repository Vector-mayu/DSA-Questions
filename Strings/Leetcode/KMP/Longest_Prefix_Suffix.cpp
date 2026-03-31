class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n = s.length();
        
        // LPS array
        vector<int>LPS(n,0);
        
        int prefix = 0, suffix = 1;
        
        while(suffix < n){
            // If both are equal 
            if(s[prefix] == s[suffix]){
                LPS[suffix] = prefix + 1;
                suffix++, prefix++;
            }
            // if they are not equal
            else{
                // if its 0th position of prefix 
                if(prefix == 0)
                suffix++;
                // go where str1 and str2 has common matches 
                else{
                    prefix = LPS[prefix - 1];
                }  
            }
        }
        
        return LPS[n-1];
    }
};