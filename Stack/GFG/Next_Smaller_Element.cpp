class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n, -1);
        
        // lets build ans vector
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            // if top is itself lesser then push
            st.push(i);
        }
        
        return ans;
    }
};