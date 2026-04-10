class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>> rows(10, vector<int> (10,0));
        vector<vector<int>> cols(10, vector<int> (10,0));
        vector<vector<int>> subMat(10, vector<int> (10,0));
        
        for( int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int val = board[i][j] - '0';
                if(rows[i][val]==1) return false;
                rows[i][val] = 1;
                if(cols[j][val]==1) return false;
                cols[j][val] = 1;
                int idx = (i/3)*3 + j/3;
                if(subMat[idx][val]==1) return false;
                subMat[idx][val] = 1;
            }
        }
        return true;  
    }
};
