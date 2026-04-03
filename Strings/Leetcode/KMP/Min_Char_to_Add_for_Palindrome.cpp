class Solution {
  public:
    int minChar(string &s) {
        // code here
        int n = s.size();
        string temp = s;
        // Reverse the string 
        reverse(temp.begin(), temp.end());
        
        // now add the string in the back of s string
        // by this we can now apply LPS to it 
        // if the String was :- NOONISP then reverse of it is :- PSINOON
        // we can see that the chars which are in palindrome didnt change
        
        s += temp;
        vector<int>LPS(s.size(),0);
        
        int prefix = 0, suffix = 1;
        
        // apply LPS to get the max value of palin present in it
        while(suffix < s.size()){
            if(s[prefix] == s[suffix]){
                LPS[suffix] = prefix + 1;
                suffix++, prefix++;
            }
            else{
                if(prefix == 0){
                    suffix++;
                }
                else{
                    prefix = LPS[prefix - 1];
                }
            }
        }
        
        // if value is -ve then its a palindrome as it do not need any element to make one
        if(n - LPS[s.size()-1] >= 0)
        return n - LPS[s.size()-1];
        
        return 0;
    }
};
