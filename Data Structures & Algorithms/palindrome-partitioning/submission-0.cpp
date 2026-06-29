class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(int left, int right, string s) {
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(int start, vector<string> curr, string s) {
        if(start == s.length()) {
            ans.push_back(curr);
            return;
        }
        for(int end=start;end<s.length();end++){
            if(isPalindrome(start, end,s)){
                curr.push_back(s.substr(start, end-start+1));
                backtrack(end+1,curr,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(0,curr,s);
        return ans;      
    }
};
