// TC :- O(n*m)
// SC :- O(1)

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int count = 0; // calculate if its a match
        for(int i=0; i < n-m; i++){
            int k = 0; // k points the start element of pattern
            while(k < m){
                if(pattern[k] == 1 && nums[i + k + 1] > nums[i + k]){
                    k++;
                }
                else if(pattern[k] == 0 && nums[i + k + 1] == nums[i + k]){
                    k++;
                }
                else if(pattern[k] == -1 && nums[i + k + 1] < nums[i + k]){
                    k++;
                }
                else{
                    break;
                }
            }

            // match condition
            if(k == m)
            count++;
        }

        return count;
    }
};