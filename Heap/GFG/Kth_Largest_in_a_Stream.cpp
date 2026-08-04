class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.begin()+k);
        
        // we will process all elements but will maintain a k sized heap
        // so that the min heaps top is my kth largest element
        
        // untill we push vals till k our heap is not full yet so 0---->k-1 ans will be -1
        vector<int>ans(k-1, -1);
        // also push kth element 
        ans.push_back(pq.top());
        
        for(int i=k; i<arr.size(); i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
            
            ans.push_back(pq.top());
        }
        
        return ans;
    }
};