class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>q;
        int n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            q.push(arr[i]);
        }
        
        
        for(int i=0; i<n; i++){
            arr[i] = q.top();
            q.pop();
        }
    }
};