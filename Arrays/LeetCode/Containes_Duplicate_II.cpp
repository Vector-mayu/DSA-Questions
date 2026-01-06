class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        long long int n = nums.size();

        // for(long long int i=0;i<=n-1;i++)
        // {
        //     for(long long int j=i+1; j<=n-1; j++)
        //     {
        //         if(nums[i] == nums[j] && abs(i-j)<=k)
        //         {
        //             return true;
        //         }
        //     }
        // }

        // return false;
        map<int, int>m;
        for(int i=0; i<n; i++)
        {
            if(m.find(nums[i]) != m.end() && abs(m[nums[i]] - i) <= k)
            {
                return true;
            }
            else{
                m[nums[i]] = i;
            }
        }

        return false;


    }
};