class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = 10001;
        int sellPrice = 0;
        int totalProfit = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            if (buyPrice == 10001) {  // no stock
                if (prices[i - 1] < prices[i]) { // buy
                    buyPrice =  prices[i - 1];
                    sellPrice = prices[i];
                }
            } else {  // got stock
                if (prices[i - 1] > prices[i]) { // sell
                    totalProfit += sellPrice - buyPrice;
                    buyPrice = 10001;
                    sellPrice = 0;
                } else { // imrove exit point
                    sellPrice = prices[i];
                }
            }
        }
        cout << sellPrice << " - " << buyPrice << endl; 
        if (sellPrice - buyPrice > 0) {
            totalProfit += sellPrice - buyPrice;
        }
        return totalProfit;
    }
};