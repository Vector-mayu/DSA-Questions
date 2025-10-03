// Given an array, arr[] of rope lengths, connect all ropes in
// to a single rope with the minimum total cost. The cost to 
// connect two ropes is the sum of their lengths. 


class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        priority_queue<long long, vector<long long>, greater<long long>>p;
        
        // Step 1 : Push the elements of Array into Priority Queue
        for(long long i=0; i<arr.size(); i++)
        p.push(arr[i]);
        
        long long cost = 0;
        
        // Step 2 : Keep Pushing the values until queue is <= 1
        while(p.size() > 1)
        {
            // add 1st value into rope
            long long rope = p.top();
            p.pop();
            
            // Add Second Value in the rope
            rope+= p.top();
            p.pop();
            
            // Inc cost and push rope again
            cost += rope;
            p.push(rope);
        }
        
        return cost;
        
        
        
    }
};