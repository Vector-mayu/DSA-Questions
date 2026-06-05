class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;

        // will create a map for all elements
        for(int i=0; i< 2*n-1; i++){
            int idx = i%n; // access within range elements

            while(!st.empty() && nums[st.top()] < nums[idx]){
                ans[st.top()] = nums[idx];
                st.pop();
            }
            // push elements only in 1st pass to avoid duplicate elements 
            if(i<n){
                st.push(i);
            }
        }

        return ans;
    }
};