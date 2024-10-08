class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int ind = n-1;ind>=0;ind--){
            for(int Transaction=0;Transaction<2*k;Transaction++){
                int profit;
             if(Transaction % 2==0){
                 profit = max(-prices[ind] + dp[ind+1][Transaction+1],dp[ind+1][Transaction]);
               }else{
                 profit = max( prices[ind] + dp[ind+1][Transaction+1],dp[ind+1][Transaction]);
              }
              dp[ind][Transaction]=profit;
            }
        }
       
        return dp[0][0];
    }
};