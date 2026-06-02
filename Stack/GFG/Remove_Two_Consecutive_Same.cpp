class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // code here
        int n = arr.size();
        stack<string>s;
        
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(s.empty()){
                count = 1;
                s.push(arr[i]);
            }
            else{
                if(s.top() == arr[i]){
                    s.pop();
                    count--;
                }
                else{
                    count++;
                    s.push(arr[i]);
                }
            }
        }
        return count;
    }
};