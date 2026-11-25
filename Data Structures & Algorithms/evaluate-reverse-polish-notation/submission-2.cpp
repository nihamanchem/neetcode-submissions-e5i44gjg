class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> op = {"+","-","*","/"};
        for(string s:tokens){
            if(op.find(s)==op.end()){
                stk.push(stoi(s));
            } else {
                int top1 = stk.top();
                stk.pop();
                int top2 = stk.top();
                stk.pop();
                if(s=="+") {
                    stk.push(top2+top1);
                } else if(s=="-") {
                    stk.push(top2-top1);
                } else if(s=="*") {
                    stk.push(top1*top2);
                } else if(s=="/") {
                    stk.push(top2/top1);
                }
            }
        }
        return stk.top();
    }
};
