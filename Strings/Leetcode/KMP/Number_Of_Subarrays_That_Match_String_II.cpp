class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        vector<int>temp;
        // we will convert the question into pattern
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1])
            temp.push_back(1);
            else if(nums[i] == nums[i+1])
            temp.push_back(0);
            else
            temp.push_back(-1);
        }

        // calculate LPS for pattern array
        vector<int>LPS(m, 0);
        int prefix = 0, suffix = 1;

        while(suffix < m){
            if(pattern[suffix] == pattern[prefix]){
                LPS[suffix] = prefix + 1;
                suffix++, prefix++;
            }
            else{
                if(prefix == 0)
                suffix++;
                else
                prefix = LPS[prefix - 1];
            }
        }

        prefix = 0, suffix = 0;
        int count = 0;

        // pattern matching in temp string
        while(suffix < temp.size()){
            if(temp[suffix] == pattern[prefix]){
                if(prefix == m-1){
                    count++;
                    prefix = LPS[prefix];
                    suffix++;
                    continue;
                }
                suffix++, prefix++;
            }
            else{
                if(prefix == 0)
                suffix++;
                else
                prefix = LPS[prefix - 1];
            }
        }

        return count;
    }
};