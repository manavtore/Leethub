class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
       int currNotBuy=0 , currBuy = 0;
        int aheadNotBuy = 0, aheadBuy = 0;

        for(int i=n-1;i>=0;i--){
            
            currNotBuy = max(prices[i] + aheadBuy, aheadNotBuy);

            currBuy = max(-prices[i] + aheadNotBuy - fee,aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;


    }
};