class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return {0};
        }

        vector<int>ans;
        for(int i=0; i<n-1; i++){
            if(nums[i] % 2 == 0){// even
                int count = 0;
                for(int j=i+1; j<n; j++){
                    if(nums[j] %2 == 1){
                        count++;
                    }
                }
                ans.push_back(count);
            }
            else{// odd
                int count = 0;
                for(int j=i+1; j<n; j++){
                    if(nums[j] %2 == 0){
                        count++;
                    }
                }
                ans.push_back(count);
            }
        }
        ans.push_back(0);
        return ans;
    }
};