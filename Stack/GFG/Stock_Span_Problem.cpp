class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n,1);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            //if stack is empty then push i+1 value 
            // can happen at 0 index 
            // also can happen when arr[i] greater than every index
            if(st.empty()){
                ans[i] = i+1;
            }
            // if not empty then simply i - previous top value
            else{
                ans[i] = i - st.top();
            }
            st.push(i);
        }
        
        return ans;
    }
};