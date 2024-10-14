class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> prev(amount+1,0);
        
        prev[0] = 1;
    
        for(int ind=0;ind<n;ind++){
            vector<int> curr(amount+1,0);
            curr[0] = 1; 
            for(int amt = 1; amt<=amount ; amt++){
                  long long exclude = prev[amt];

                  long long include = 0;
                  if(coins[ind] <= amt){
                    include = curr[amt- coins[ind]];
                   }
                  curr[amt] = include + exclude ;
            }
            prev = curr;
        }
        return prev[amount];
    }
};