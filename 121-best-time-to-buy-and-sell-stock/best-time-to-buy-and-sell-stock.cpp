class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int least = prices[0];
        int currentProfit;
        for(int i=1;i<prices.size();i++){
            currentProfit = prices[i]-least;
            profit = max(currentProfit,profit);
            least = min(prices[i],least);
        }
        return profit;
    }
};