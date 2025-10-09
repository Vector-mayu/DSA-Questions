class Solution {
public:
    int largestRectangleArea(vector<int>& height) {

        int index;
        int ans = 0;
        stack<int>st;
        int n = height.size();

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && height[st.top()]>height[i])
            {
                index = st.top();
                st.pop();

                if(!st.empty())
                {
                  ans = max(ans, height[index]*(i-st.top()-1));  
                }
                else
                {
                    ans = max(ans, height[index]*(i));
                }
            }
            st.push(i);
        }

        while(!st.empty())
        {
            index = st.top();
            st.pop();

            if(!st.empty())
            {
                ans = max(ans, height[index]*(n-st.top()-1));
            }
            else
            {
                ans = max(ans, height[index]*(n));
            }
        }

        return ans;
        
    }
};