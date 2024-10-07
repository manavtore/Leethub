class Solution {
    int buyandsell(vector<int>& prices,int ind,int buy,int cap, vector<vector<vector<int>>>& dp){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(
                        -prices[ind] + buyandsell(prices,ind+1,0,cap,dp),
                        0 + buyandsell(prices,ind+1,1,cap,dp)
            );
        }else{
             profit = max(
                        prices[ind] + buyandsell(prices,ind+1,1,cap-1,dp),
                        buyandsell(prices,ind+1,0,cap,dp)
                         );
        }
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                 int profit = 0;
                 if(buy){
                        profit = max(
                        -prices[ind] + buyandsell(prices,ind+1,0,cap,dp),
                        0 + buyandsell(prices,ind+1,1,cap,dp)
                        );
                    }else{
                        profit = max(
                        prices[ind] + buyandsell(prices,ind+1,1,cap-1,dp),
                        buyandsell(prices,ind+1,0,cap,dp)
                         );
                  }
                  dp[ind][buy][cap] = profit;
                }
            }
        }

         return dp[0][1][2];
    }
};