class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<=amount ;i++){
          if (i % coins[0] == 0)
               dp[0][i] = 1;
           }
    
        for(int ind=1;ind<n;ind++){
            for(int amt = 0; amt<=amount ; amt++){
                  long long exclude = dp[ind-1][amt];

                  long long include = 0;
                  if(coins[ind] <= amt){
                    include = dp[ind][amt- coins[ind]];
                   }
                  dp[ind][amt] = include + exclude ;
            }
        }
        return dp[n-1][amount];
    }
};