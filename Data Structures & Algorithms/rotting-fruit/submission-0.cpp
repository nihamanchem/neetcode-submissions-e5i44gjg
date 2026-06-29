class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        int ans=0;
        int directions[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int qSize=q.size();
            for(int j=0;j<qSize;j++){
                auto [row,col]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int r=row+directions[i][0];
                    int c=col+directions[i][1];
                    if(r<0||r>=m||c<0||c>=n||grid[r][c]!=1) continue;
                    grid[r][c]=2;
                    fresh--;
                    q.push({r,c});
                }
            }
            ans++;
        }
        return fresh ==0 ? ans : -1;
    }
};
