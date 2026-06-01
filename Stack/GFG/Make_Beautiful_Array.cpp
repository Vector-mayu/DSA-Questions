class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        int n = arr.size();
        stack<int>st;
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(arr[i]);
            }
            else{
                if((st.top() >= 0 && arr[i] < 0) || (st.top() <0 && arr[i] >= 0)){
                    st.pop();
                }
                else{
                    st.push(arr[i]);
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};