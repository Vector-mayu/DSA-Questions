class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(q.size() < k){
            return q;
        }
        
        stack<int>st;
        int it = k;
        while(it){
            st.push(q.front());
            q.pop();
            it--;
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        while(q.size() - k){
            q.push(q.front());
            q.pop();
            k++;
        }
        
        return q;
    }
};