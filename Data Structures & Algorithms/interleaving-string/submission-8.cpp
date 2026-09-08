class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(),m=s2.length();
        if(n+m!=s3.length()) return false;

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[n][m]=true;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(s3[i+j]==s1[i] && i<n && dp[i+1][j]){
                    dp[i][j]=true;
                }
                if(s3[i+j]==s2[j] && j<m && dp[i][j+1]){
                    dp[i][j]=true;
                }
            }
        }
        return dp[0][0];    
    }
};
