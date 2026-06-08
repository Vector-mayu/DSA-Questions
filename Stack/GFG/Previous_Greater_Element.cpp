int n = arr.size();
        stack<int>st;
        vector<int>ans(n, -1);
        
        // lets build ans vector
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            // if top is itself lesser then push
            st.push(i);
        }
        
        return ans;