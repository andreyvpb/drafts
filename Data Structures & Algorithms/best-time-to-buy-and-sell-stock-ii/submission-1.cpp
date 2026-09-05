class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = 0;
        int sellPrice = 0;
        int totalProfit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (buyPrice == sellPrice) {          // no stock
                if (prices[i - 1] < prices[i]) {  // buy
                    buyPrice = prices[i - 1];
                    sellPrice = prices[i];
                }
            } else {                              // got stock
                if (prices[i - 1] > prices[i]) {  // sell
                    totalProfit += sellPrice - buyPrice;
                    buyPrice = 0;
                    sellPrice = 0;
                } else {  // imrove exit point
                    sellPrice = prices[i];
                }
            }
        }
        totalProfit += sellPrice - buyPrice;
        return totalProfit;
    }
};