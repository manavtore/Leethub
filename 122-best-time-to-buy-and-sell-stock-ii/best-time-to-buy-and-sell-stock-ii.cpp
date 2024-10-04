class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n==0) return 0;

        vector<int> ahead(2,0), curr(2,0);

        int currNotBuy=0 , currBuy = 0;
        int aheadNotBuy = 0, aheadBuy = 0;

        int profit;
        for(int i=n-1;i>=0;i--){
       

             currBuy = max(0 + aheadBuy, -prices[i] + aheadNotBuy);

           currNotBuy = max(0 + aheadNotBuy, prices[i] + aheadBuy);
                      


            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;
        }

         return aheadBuy;
    }
};