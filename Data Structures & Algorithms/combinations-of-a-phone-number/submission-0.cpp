class Solution {
public:
    vector<string> ans;
    void backtrack(int start, string digits, string curr){
        if(digits.length()==curr.length()) {
            ans.push_back(curr);
            return;
        }
        unordered_map<char,vector<char>> mapToChar = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        vector<char> it = mapToChar[digits[start]];
        for(int i=0;i<it.size();i++){
            curr+=it[i];
            backtrack(start+1,digits, curr);
            curr.pop_back();
        }
      
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string curr = "";
        backtrack(0,digits,curr);
        return ans;        
    }
};
