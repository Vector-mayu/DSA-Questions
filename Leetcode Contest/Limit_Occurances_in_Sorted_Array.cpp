class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        int count = 0;
        int curr;
        
        for(int i=0; i<n; i++){
            curr = nums[i];
            if(ans.empty()){
                ans.push_back(nums[i]);
                count++;
            }
            else{
                if(count==k && curr == ans.back()){
                    continue;
                }
                else if(count < k && curr == ans.back()){
                    count++;
                    ans.push_back(curr);
                }
                else if(count <= k && curr != ans.back()){
                    ans.push_back(curr);
                    count = 1;
                }
            }      
        }

        return ans;
    }
};