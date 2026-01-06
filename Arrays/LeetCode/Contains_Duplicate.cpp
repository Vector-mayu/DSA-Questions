class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=i+1; j<n-1;j++)
        //     {
        //         if(nums[i] == nums[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        map<int, int>m;
        for(int i=0; i<n; i++)
        {
            if(m.find(nums[i]) != m.end())
            return true;
            else
            m[nums[i]] = i;
        }
        return false;
    }
};