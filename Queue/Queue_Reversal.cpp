class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        
        stack<int>st;
        
        //make queue empty and stack full
        while(!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
        
        //Empty stack and queue full
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        
        return q;
        
    }
};