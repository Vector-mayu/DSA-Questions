// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        priority_queue<int>p; // Max Heap Priority Queue
        
        for(int i=0; i<k; i++) // Start with k-1 
        {
            p.push(arr[i]);
        }
        
        for(int i=k; i<arr.size(); i++) // resume from k
        {
            if(arr[i] < p.top()) // if any smaller element then push into queue and pop greatest element from queue 
            {
                p.pop();
                p.push(arr[i]);
            }
        }
        
        return p.top(); // return kth smallest which the largest elemen in that k priority queue
    }
};