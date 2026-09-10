class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return dfs(word1,word2,0,0,dp);
    }
    int dfs(string &word1, string &word2, int i, int j,vector<vector<int>> &dp){
        int m = word1.length(), n=word2.length();
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dfs(word1,word2,i+1,j+1,dp);
        int ans = 0;
        ans = min(dfs(word1,word2,i+1,j,dp),dfs(word1,word2,i,j+1,dp));
        ans = min(ans,dfs(word1,word2,i+1,j+1,dp));
        dp[i][j]=1+ans;
        return dp[i][j];
    }
};
