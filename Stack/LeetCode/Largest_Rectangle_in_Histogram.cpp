class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>NSR(n);
        vector<int>NSL(n,-1);

        // lets find NSR
        for(int i=0; i<n; i++){
            // while will execute itslef untill heights of i is lesser than st.top
            while(!st.empty() && heights[st.top()] > heights[i]){
                // we will simply push index in here
                NSR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // if there are still elements in stack then assign them with n(cuz they dont have next smallest)
        while(!st.empty()){
            NSR[st.top()] = n;
            st.pop();
        }
        //now the stack is empty again 

        // lets make NSL now 
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                // we will simply push index in here
                NSL[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // here we dont need as we move left max n would be = -1

        // its formula time
        int maxArea = 0;    
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, (NSR[i] - NSL[i] -1) *heights[i]);
        }

        return maxArea;

    }
};