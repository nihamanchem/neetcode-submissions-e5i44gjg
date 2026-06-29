class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> m = {{')','('},{']','['},{ '}','{'}};
        for(char c : s){
            if(m.count(c)) {
                if(!stk.empty() && stk.top()==m[c]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};
