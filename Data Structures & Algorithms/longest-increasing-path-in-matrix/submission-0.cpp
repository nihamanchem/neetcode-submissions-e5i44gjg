class Solution {
public:
    vector<vector<int>> directions = {{0,-1},{0,1},{1,0},{-1,0}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS=matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS,0));
        int ans=0;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                ans=max(ans,dfs(r,c,matrix, INT_MIN, dp));
            }
        }
        return ans;
    }
    int dfs(int row, int col, vector<vector<int>> &matrix, int prevMax, vector<vector<int>> &dp){
        int ROWS=matrix.size(), COLS = matrix[0].size();
        if(row<0 || row>=ROWS || col<0 || col>=COLS ||
            matrix[row][col]<=prevMax){
            return 0;
        }
        if(dp[row][col]!=0) return dp[row][col];
        int res = 1;
        for(auto &it: directions){
            res = max(res, 1+dfs(row+it[0],col+it[1],matrix,matrix[row][col],dp));
        }
        dp[row][col]=res;
        return res;
    }
};
