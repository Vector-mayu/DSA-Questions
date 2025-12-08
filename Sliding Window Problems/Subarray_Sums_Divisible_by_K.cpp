class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int total=0, PrefixSum=0, rem;
        unordered_map<int, int>m;
        m[0]=1;

        for(int i=0; i<nums.size(); i++)
        {
            // Calculate Prefix Sum
            PrefixSum += nums[i];

            //Calculate Reminder
            rem = PrefixSum % k; // We want divisible by k 

            if(rem < 0) // if reminder is neagtive make it positive
            {
                rem += k;
            }

            if(m.count(rem))
            {
                total+= m[rem];
                m[rem]++;
            }
            else
            {
                m[rem]++;
            }
        }
        return total;
        
    }
};

// Optimized Approach