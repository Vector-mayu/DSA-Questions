class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();

        for(int i=0; i<k-1; i++){
            while(!dq.empty() && nums[dq.front()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int>ans;

        // Sliding window algo here
        for(int i=k-1; i<n; i++){
            // here will compare the kth-1(as it array so -1) element with already pushed(the back element) elements in earlier loop 
            // if back element in the deque is samller then pop it or else push the new kth-1 element in window
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            // check if the front element of deque is wihtin the current window range
            if(dq.front() <= i-k){
                dq.pop_front();
            }

            // after all checks simply push the front element which is the biggest in the window 
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};