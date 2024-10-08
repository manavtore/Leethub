class Solution {
    int solveMaxProfit(int k,vector<int>& prices,int Transaction,int ind,int n,vector<vector<int>>& dp){
        if(ind == n || Transaction == 2 * k ) return 0;
        if(dp[ind][Transaction] != -1) return dp[ind][Transaction];
        int profit;
        if(Transaction % 2==0){
            profit = max(-prices[ind] + solveMaxProfit(k,prices,Transaction+1,ind+1,n,dp),
                        solveMaxProfit(k,prices,Transaction,ind+1,n,dp));
        }else{
            profit = max( prices[ind] + solveMaxProfit(k,prices,Transaction+1,ind+1,n,dp),
                        solveMaxProfit(k,prices,Transaction,ind+1,n,dp));
        }
        return dp[ind][Transaction]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
       
        return solveMaxProfit(k,prices,0,0,n,dp);
    }
};