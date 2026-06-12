class Solution {
  public:
    void reverseArray(vector<int>& arr) {
        // code here
        stack<int>st;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            st.push(arr[i]);
        }
        
        for(int i=0; i<n; i++){
            arr[i] = st.top();
            st.pop();
        }
    }
};