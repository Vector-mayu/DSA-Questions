class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int>SuffixMax(n);

        SuffixMax[n-1] = prices[n-1];

        for(int i=n-2; i>-1; i--){
            SuffixMax[i] = max(prices[i], SuffixMax[i+1]);
        }

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(prices[i] < SuffixMax[i+1]){
                ans = max(ans, SuffixMax[i+1] - prices[i]);
            }
        }
        return ans;
    }
};