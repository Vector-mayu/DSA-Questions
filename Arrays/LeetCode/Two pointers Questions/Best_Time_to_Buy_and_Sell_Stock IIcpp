class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int MaximumProfit = 0;

        for(int i=1; i<n; i++){
            int buy = prices[i-1];
            int sell = prices[i];

            if(sell > buy){
                MaximumProfit += sell - buy;
            }
        }
        return MaximumProfit;
    }
};