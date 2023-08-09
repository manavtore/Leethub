class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least=prices[0];
        int profit=0;
        int currentprofit=0;
        
        for(int i=1;i<prices.size();i++){
          currentprofit=prices[i]-least;
         profit= max(profit,currentprofit);
           least= min(prices[i],least);  
               
        }
     
        return profit;
    }
};