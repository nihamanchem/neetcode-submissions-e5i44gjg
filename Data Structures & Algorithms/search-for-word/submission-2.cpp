class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i,int j, int k, string word){
        if(k==word.size()) return true;
        if(i<0 || j<0 ||i>=board.size() || j>=board[0].size() ||
        board[i][j]!=word[k]) return false;
        char temp = board[i][j];
        board[i][j]='#';
        bool present = dfs(board,i-1,j,k+1,word) ||
        dfs(board,i,j-1,k+1,word) ||
        dfs(board,i+1,j,k+1,word) ||
        dfs(board,i,j+1,k+1,word);
        board[i][j]=temp;
        return present;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,i,j,0,word)) return true;
            }
        }
        return false;
    }
};
