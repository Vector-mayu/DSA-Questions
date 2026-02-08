// Binaray Search Approach :- TC:- (NlogN)

class Solution {
public:

    bool BinarySearch(int Target, vector<int>&arr, int start, int end, vector<int>&ans){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(arr[mid] == Target){
                ans[1] = mid+1;
                return true;
            }
            else if(arr[mid] > Target)
            end = mid - 1;
            else
            start = mid + 1;
        }

        return false;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), start, end=n-1, newTarget;
        vector<int>ans(2,0);

        for(int i=0; i<n; i++){
            newTarget = target - numbers[i];
            ans[0] = i+1;
            start = i+1;
            if(BinarySearch(newTarget, numbers, i+1, end, ans)){
                break;
            }
        }
        return ans;
    }
};

// Two Pointers Approach TC :- (LogN)

