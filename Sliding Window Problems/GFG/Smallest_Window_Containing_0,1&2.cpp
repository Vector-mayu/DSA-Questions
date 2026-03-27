// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int n = S.length();
        int temp = 3;
        
        int freq[3] = {0};
        for(int i=0; i<n; i++){
            if(freq[S[i] - '0'] == 0){
                temp--;
                freq[S[i] - '0'] = 1;
            }
        }
        
        if(temp != 0)
        return -1;
        
        int uniqueChar = 3;
        vector<int>count(3, 0);
        int start = 0, end = 0, currUniqueChar = 0, minLen = S.length(); 
        
        while(end < n){
            // Mark the count of the curr char
            count[S[end] - '0']++;
            
            //is that char came first time then update curr unique
            if(count[S[end] - '0'] == 1)
            currUniqueChar++;
            
            // if they match 
            while(currUniqueChar == uniqueChar){
                minLen = min(minLen,end-start+1);
                count[S[start] - '0']--;
                
                if(count[S[start] - '0'] == 0)
                currUniqueChar--;
                
                start++;
            }
            end++;
        }
        
        return minLen;
    }
};
