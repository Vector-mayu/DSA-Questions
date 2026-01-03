// Brute Force

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;
        vector<int>arr;
        for(int i=n-k; i<n;i++)
        {
            arr.push_back(nums[i]);
        }

        int m=n-k;
        for(int i=m-1; i>=0; i--){
            nums[i+k] = nums[i];
        }

        for(int i=0; i<k; i++)
        {
            nums[i] = arr[i];
        }
        
    }
};

// Optimization 1 
class Solution {
  public:
    void rotateclockwise(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>nums(n);
        
        for(int i=0; i<n; i++)
        {
            nums[(i+k)%n] = arr[i];
        }
        
        for(int i=0; i<n; i++)
        {
            arr[i] = nums[i];
        }
    }
};

// Optimization 2 (GFG)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};