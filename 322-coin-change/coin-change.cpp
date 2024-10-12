class Solution {
    int coinChangeRecursive(vector<int>& coins,int amount,int ind,vector<vector<int>>& dp){ 
        if (amount == 0) return 0;
        if (ind < 0 || amount < 0) return INT_MAX;
        
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int exclude = coinChangeRecursive(coins, amount, ind - 1, dp);

        int include = INT_MAX;

        if(coins[ind] <= amount){
           int res = coinChangeRecursive(coins,amount-coins[ind],ind ,dp);
             if (res != INT_MAX) {
                include = 1 + res; 
            }
        }

        return dp[ind][amount] = min(exclude,include);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
         int result = coinChangeRecursive(coins, amount, coins.size() - 1,dp);
        
        return (result == INT_MAX) ? -1 : result;
    }
};