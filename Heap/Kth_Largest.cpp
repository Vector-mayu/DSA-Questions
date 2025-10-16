class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // MinHeap
        priority_queue<int, vector<int>, greater<int>>p;

        // Pushed k elements
        for(int i=0; i<k; i++)
        {
            p.push(nums[i]);
        }

        // Check and insert according to condition
        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > p.top())
            {
                p.pop();
                p.push(nums[i]);
            }
        }

        return p.top();

        
    }
};