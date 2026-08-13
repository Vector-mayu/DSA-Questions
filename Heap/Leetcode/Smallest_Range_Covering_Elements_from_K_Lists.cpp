// Time Complexity = O(N log k)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // we will have Min heap who will keep track of min element in the range
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        // push all start elements of each row
        // also make the initial min and max window
        int minElement = nums[0][0], maxElement = nums[0][0];

        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            minElement = min(minElement, nums[i][0]);
            maxElement = max(maxElement, nums[i][0]);
        }

        // now we have 1.MIN heap, minElement and maxElement 
        // we will initially push min and max into ans vector
        vector<int>ans;
        ans.push_back(minElement);
        ans.push_back(maxElement);

        pair<int, pair<int, int>>temp;
        int row , col;

        // we will stop when any 1D array is over
        while(pq.size() == nums.size()){
            temp = pq.top();
            pq.pop();

            row = temp.second.first;
            col = temp.second.second;

            col++;
            // if any 1D array ends
            if(col == nums[row].size()){
                break;
            }

            // if 1D is still in range then push in min heap
            pq.push({nums[row][col], {row, col}});

            // update current min and max element
            minElement = pq.top().first;
            maxElement = max(maxElement, nums[row][col]);

            // now lets check the current window with previosly added window
            if(maxElement-minElement < ans[1]-ans[0]){
                ans[0] = minElement;
                ans[1] = maxElement;
            }
        }

        return ans;
    }
};