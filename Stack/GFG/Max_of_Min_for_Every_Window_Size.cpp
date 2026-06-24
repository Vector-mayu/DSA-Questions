class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        stack<int>st1;
        int n = arr.size();
        vector<int>NSR(n, n);
        
        // lets find the Next Smallest Right
        for(int i=0; i<n; i++){
            // if ith element coming in stack is lesser than top element -> then we have got our next smaller
            while(!st1.empty() && arr[st1.top()] > arr[i]){
                NSR[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
        
        stack<int>st2;
        vector<int>NSL(n, -1);
        
        // lets create Next Smaller Left
        for(int i=n-1; i>=0; i--){
            // if the ith element coming in stack is lesser than top element -> then we have got our next smaller
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                NSL[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
        
        vector<int>ans(n,0);
        // we have NSR and NSL 
        // lets calculate max window size of ith element
        for(int i=0; i<n; i++){
            int len = (NSR[i] - NSL[i]) - 1;
            ans[len-1] = max(ans[len-1], arr[i]);
        }
        
        // there will be positions where we have repeated numbers, we have uniquely pushed in ans
        // also we need the ans array in max -> min order
        // hence we will just max them in from rigt to left
        for(int i=n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        return ans;
    }
};