class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(amount+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int a=0;a<=amount;a++){
                if(a>=coins[i]){
                    dp[a][i]=dp[a][i+1]+dp[a-coins[i]][i];
                } else {
                    dp[a][i] = dp[a][i+1];   
                }
            }
        }
        return dp[amount][0];
        
    }
};
