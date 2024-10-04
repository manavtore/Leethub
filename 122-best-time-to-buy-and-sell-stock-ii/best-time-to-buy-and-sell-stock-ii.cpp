class Solution {
    int calculateProfit(vector<int>& prices,int ind,int buy,vector<vector<int>>& dp){
        int n = prices.size();
        if(ind == n) return 0;

        if(dp[ind][buy]!= -1) return dp[ind][buy];

        int profit;
        if(buy==0){
            profit = max(0 + calculateProfit(prices,ind+1,0,dp), - prices[ind] + calculateProfit(prices,ind+1,1,dp) );
        }else{
            profit = max(0 + calculateProfit(prices,ind+1,1,dp), prices[ind] + calculateProfit(prices,ind+1,0,dp) );
        }

        return dp[ind][buy] = profit;

    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n==0) return 0;

        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = calculateProfit(prices,0,0,dp);
        return ans;
    }
};