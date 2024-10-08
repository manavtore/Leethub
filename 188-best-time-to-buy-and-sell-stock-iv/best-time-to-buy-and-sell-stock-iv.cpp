class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2*k+1,0);
        vector<int> curr(2*k+1,0);

        for(int ind = n-1;ind>=0;ind--){
            for(int Transaction=0;Transaction<2*k;Transaction++){
                int profit;
             if(Transaction % 2==0){
                 profit = max(-prices[ind] + prev[Transaction+1],prev[Transaction]);
               }else{
                 profit = max( prices[ind] + prev[Transaction+1],prev[Transaction]);
              }
              curr[Transaction]=profit;
            }
            prev = curr;
        }
       
        return prev[0];
    }
};