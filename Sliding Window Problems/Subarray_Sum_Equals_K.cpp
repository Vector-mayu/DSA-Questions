class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        long long int total = 0;
        long long int PrefixSum =0;
        // Make a unordered map
        unordered_map<long long int, long long int>m;

        // initialize the map with ('0'->1)
        m[0]=1;

        for(int i=0;i<nums.size();i++)
        {
            // add element in PrefixSum
            PrefixSum += nums[i];

            if(m.count(PrefixSum-k))
            {
                total += m[PrefixSum-k]; // update the total
                m[PrefixSum]++; // update m[count]
            }
            else
            {
                m[PrefixSum]++; // if not then increase the occurance
            }
        }

        return total;
        
    }
};