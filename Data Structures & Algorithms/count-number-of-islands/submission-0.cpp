class Solution {
public:
    int ans=0;
    void dfs(int row, int col, vector<vector<char>> &grid){
        if(row<0 || row >= grid.size() || col<0 || 
        col>=grid[0].size() || grid[row][col]=='0'){
            return;
        }
        grid[row][col]='0';
        int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            dfs(row+directions[i][0],col+directions[i][1],grid);
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int row=grid.size(), col = grid[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]== '1'){
                    dfs(r,c,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
