class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowCheck = false;
        int rows=matrix.size(), col= matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    // set col start =0
                    matrix[0][j]=0;
                    if(i==0) {
                        firstRowCheck = true;
                    } else {
                        matrix[i][0]=0;
                    }

                }
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<rows;i++) matrix[i][0]=0;
        }
        if(firstRowCheck){
            for(int j=0;j<col;j++) matrix[0][j]=0;
        }
    }
};
