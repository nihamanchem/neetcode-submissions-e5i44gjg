class Solution {
public:
    int dfs(int row,int col, vector<vector<int>> &grid){
        int area=0;
        int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        if(row<0 || row>=grid.size() || col<0 ||
        col>=grid[0].size() || grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;
        area++;
        for(int i=0;i<4;i++){
            area+=dfs(row+directions[i][0],col+directions[i][1],grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int maxArea=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea,dfs(i,j,grid));
                }
            }
        }
      return maxArea;  
    }
};
