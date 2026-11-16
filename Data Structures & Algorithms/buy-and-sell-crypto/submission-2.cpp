class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,maxStockPrice=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]>maxStockPrice){
                maxStockPrice=prices[i];
            } else {
                maxProfit = max(maxProfit,maxStockPrice-prices[i]);
            }
        }
        return maxProfit;
    }
};
