class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        // for(int i=0;i<n;i++){
        //     dp[i][0] = 0;
        // }

        for(int ind=0;ind<n;ind++){
            for(int amt = 1;amt<=amount;amt++){
                int exclude = (ind>0) ? prev[amt] :INT_MAX;

                int include = INT_MAX;

                if(coins[ind] <= amt){
                int res = curr[amt-coins[ind]];
                    if (res != INT_MAX) {
                        include = 1 + res; 
                 }
             }

              curr[amt] = min(exclude,include);
            }
            prev = curr;
        }
         int result = prev[amount];
        
        return (result == INT_MAX) ? -1 : result;
    }
};