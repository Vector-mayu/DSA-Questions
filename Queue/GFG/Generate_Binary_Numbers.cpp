class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        queue<string>q;
        vector<string>ans;
        
        // initially push 1 into queue
        q.push("1");
        
        while(!q.empty()){
            q.push(q.front()+"0");
            q.push(q.front()+"1");
            ans.push_back(q.front());
            q.pop();
            if(ans.size() == n){
                break;
            }
        }
        return ans;
    }
};