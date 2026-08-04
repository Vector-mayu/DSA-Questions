class Solution {
  public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        // code here
        priority_queue<pair<int, int>>pq;
        
        for(int i=0; i<k2; i++){
            pq.push({arr[i], i});
        }
        
        // process all elements
        for(int i=k2; i<arr.size(); i++){
            if(arr[i] < pq.top().first){
                pq.pop();
                pq.push({arr[i], i});
            }
        }
        
        pq.pop();
        
        int ans = 0;
        while(pq.size() > k1){
            ans += pq.top().first;
            pq.pop();
        }
        
        return ans;
    }
};