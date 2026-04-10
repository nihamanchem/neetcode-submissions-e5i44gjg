class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, j=1;
        int maxReturn=0;
        while(j<prices.size()){
            if(prices[j]>prices[i]) {
                maxReturn = max(prices[j]-prices[i], maxReturn);
            } else {
                i=j;
            }
            j++;
        }
        return maxReturn;
    }
};
