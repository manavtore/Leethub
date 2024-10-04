class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n==0) return 0;

        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        dp[n][0] = dp[n][1] = 0;
        int profit;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
;
                    profit = max(0 + dp[i+1][0], prices[i] + dp[i+1][1]);

                }
                if(buy==1){
                     profit = max(0 + dp[i+1][1], -prices[i] + dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }

         return dp[0][1];
    }
};