class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> trackP(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> trackA(heights.size(),vector<bool>(heights[0].size(),false));
        int ROWS = heights.size();
        int COLS = heights[0].size();
        queue<pair<int,int>> q;
        int directions[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        // PACIFIC TRACKING
        for(int i=0;i<ROWS;i++){
            q.push({i,0});
            trackP[i][0]=true;
        } 
        for(int j=0;j<COLS;j++){
            q.push({0,j});
            trackP[0][j]=true;
        }
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+directions[i][0];
                int c=col+directions[i][1];
                if(r<0 || r>=ROWS || c<0 || c>=COLS || heights[r][c]<heights[row][col]
                || trackP[r][c]){
                    continue;
                }
                q.push({r,c});
                trackP[r][c]=true;
            }
        }
        // ATLANTIC TRACKING
        for(int i=0;i<ROWS;i++){
            q.push({i,COLS-1});
            trackA[i][COLS-1]=true;
        } 
        for(int j=0;j<COLS;j++){
            q.push({ROWS-1,j});
            trackA[ROWS-1][j]=true;
        }
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+directions[i][0];
                int c=col+directions[i][1];
                if(r<0 || r>=ROWS || c<0 || c>=COLS || heights[r][c]<heights[row][col] || 
                trackA[r][c]){
                    continue;
                }
                q.push({r,c});
                trackA[r][c]=true;
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(trackP[i][j]&&trackA[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
