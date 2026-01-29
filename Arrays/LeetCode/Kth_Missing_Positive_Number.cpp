// Approach 1 TC:- O(N)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int fin = 0, count=0;
        int max = arr[n-1];
        vector<int>ans(max + k + 1, 0);

        for(int i=0; i<n; i++){
            ans[arr[i]]++;
        }

        for(int i=0; i<ans.size(); i++){
            if(ans[i] == 0 && count <= k){
                count++;
                fin = i;
            }
        }
        return fin;
    }
};

// Approach 2 TC :- O((n+k)logn)

class Solution {
public:

    int BinarySearch(vector<int>&arr, int target, int n, int &count){
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] == target)
            return 0;
            else if(arr[mid] > target)
            end = mid -1;
            else
            start = mid +1;
        }
        count--;
        return target;

    }

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int count = k;
        int ans;

        for(int i=1; i<=arr[n-1]+k; i++){
            ans = BinarySearch(arr, i,n, count);
            if(count == 0)
            break;
        }
        return ans;
    }
};

// Approach 3 :- O(n) 

class Solution {
public:

    int findKthPositive(vector<int>& arr, int k) {
        int missingNumber = k;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > missingNumber)
            return missingNumber;
            else
            missingNumber++;
        }
        return missingNumber;
    }
};