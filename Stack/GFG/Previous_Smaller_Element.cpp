class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        
        // we will start finidng the previous smaller element from left side
        // we will just ask if is there any smaller element on the left side
        // if yes then push in ans array as well push in stack
        // if the prev is not smaller then pop that from stack
        
        for(int i=0; i<n; i++){
            // if the top element in stack is not smaller then keep popping it
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            // we we get smaller element at top then push in answer array
            if(!st.empty() && arr[st.top()] < arr[i]){
                ans[i] = arr[st.top()];
            }
            // if we get smaller or not always push each element in stack
            st.push(i);
        }
        
        return ans;
    }
};