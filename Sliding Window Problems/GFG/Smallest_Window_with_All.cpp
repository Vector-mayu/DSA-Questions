class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.size(), target = p.size();
        
        if(n < target)
        return "";
        
        vector<int>targetCounter(128, 0);
        
        for(char c : p){
            targetCounter[c]++;
        }
        
        vector<int>windowCounter(128, 0);
        int left = 0, right = 0, startIndex = 0, minSize = INT_MAX, currTarget = 0;
        
        while(right < n){
            char c = s[right];
            windowCounter[c]++;
            
            if(targetCounter[c] && windowCounter[c] <= targetCounter[c]){
                currTarget++;
            }
            
            while(currTarget == target){
                if(right - left + 1 < minSize){
                    minSize = right - left + 1;
                    startIndex = left;
                }
                
                char a = s[left];
                if(targetCounter[a] && windowCounter[a] <= targetCounter[a]){
                    currTarget--;
                }
                
                windowCounter[a]--;
                left++;
            }
            right++;
        }
        
        return minSize == INT_MAX ? "" : s.substr(startIndex, minSize);
    }
};