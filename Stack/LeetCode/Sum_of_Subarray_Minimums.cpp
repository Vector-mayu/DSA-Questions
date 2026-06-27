// Time Complexity :-O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>NSL(n, -1);
        vector<int>NSR(n, n);
        stack<int>st1;
        stack<int>st2;
        int mod = 1e9 + 7;

        // Next Smaller Right
        for(int i=0; i<n; i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                NSR[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        // Next Smaller Left
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                NSL[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        // calcute the answer 
        long long ans = 0;

        for(int i=0; i<n; i++){
            long long totalWays = ((i - NSL[i]) * (NSR[i] - i));
            long long totalSum = arr[i] * totalWays;

            ans = (ans + totalSum)%mod;
        }

        return ans;
    }
};