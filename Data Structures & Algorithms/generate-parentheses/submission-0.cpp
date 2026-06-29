class Solution {
public:
    vector<string> ans;
    void backtrack(string curr, int open, int close, int n){
        if(curr.length()==2*n) {
            ans.push_back(curr);
            return;
        }
        if(open<n){
            backtrack(curr+"(",open+1,close,n);
        }
        if(close<open){
            backtrack(curr+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="(";
        backtrack(curr,1,0,n);
        return ans;
    }
};
