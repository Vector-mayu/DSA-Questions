class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n, -1);
        stack<int>st;
        
        // The loop starts with 0-->n*2 
        for(int i=0; i<n*2-1; i++){
            int idx = i%n; // we will only access elements within the range
            while(!st.empty() && arr[st.top()] < arr[idx]){
                ans[st.top()] = arr[idx];
                st.pop();
            }
            
            if(i<n){
                st.push(idx);
            }
        }
        return ans;
    }
};