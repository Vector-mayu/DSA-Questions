class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int s = max(1, n-k);
        int e = abs(n+k);

        int ans = 0;
        for(int i=s; i<=e; i++){
            if((abs(n-i) <= k) && ((n & i) == 0)){
                ans += i;
            }
        }

        return ans;
    }
};