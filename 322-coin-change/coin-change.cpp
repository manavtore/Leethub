class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,INT_MAX));

        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }

        for(int ind=0;ind<n;ind++){
            for(int amt = 1;amt<=amount;amt++){
                 int exclude = (ind>0) ? dp[ind - 1][amt] :INT_MAX;

                int include = INT_MAX;

                if(coins[ind] <= amt){
                int res = dp[ind][amt-coins[ind]];
                    if (res != INT_MAX) {
                        include = 1 + res; 
                 }
             }

              dp[ind][amt] = min(exclude,include);
            }
        }
         int result = dp[n-1][amount];
        
        return (result == INT_MAX) ? -1 : result;
    }
};