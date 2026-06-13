class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int>ans;
        queue<int>q;
        
        // we will push k-1 elements and start the actual window from k 
        for(int i=0; i<k-1; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        // now we will start with k window our queue has k-1 negative element
        for(int i=k-1; i<n; i++){ // we are doing because we will not go out of bound conditions
            // check if the k element is negative
            // if yes then push it
            if(arr[i] < 0){
                q.push(i);
            }
            
            // if queue exist and it is in the range of i to i-k 
            // if any element in queue is not in current window then pop it
            if(!q.empty() && q.front() <= i-k){// i=4 k=2 then range = 4-2 = 2 remove if element is 0,1,2 
                q.pop();
            }
            
            // now ans push conditions
            
            // if queue is empty then simply do this
            if(q.empty()){
                ans.push_back(0);
            }
            // after all checks if queue exist then push 1st negative number
            else{
                ans.push_back(arr[q.front()]);
            }
        }
        
        return ans;
    }
};