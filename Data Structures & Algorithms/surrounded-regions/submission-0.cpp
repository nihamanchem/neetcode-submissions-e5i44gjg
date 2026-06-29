class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS= board.size();
        int COLS= board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<ROWS;i++){
            if(board[i][0]=='O') {
                q.push({i,0});
                board[i][0]='U';
            }
            if(board[i][COLS-1]=='O') {
                q.push({i,COLS-1});
                board[i][COLS-1]='U';
            }
        }
        for(int i=0;i<COLS;i++){
            if(board[0][i]=='O') {
                q.push({0,i});
                board[0][i]='U';
            }
            if(board[ROWS-1][i]=='O') {
                q.push({ROWS-1,i});
                board[ROWS-1][i]='U';
            }
        }
        int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r = row + directions[i][0];
                int c = col + directions[i][1];
                if(r<0 || r>=ROWS || c<0 || c>=COLS || board[r][c]!='O') continue;
                board[r][c]='U';
                q.push({r,c});
            }
        }
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='U') board[i][j]='O';
            }
        }
        
    }
};
