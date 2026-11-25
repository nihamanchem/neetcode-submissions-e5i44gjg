class MinStack {
public:
    stack<int> stk;   
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();    
    }
    
    int top() {
        return stk.top();    
    }
    
    int getMin() {
        stack<int> tmpStk = stk;
        int minEle = INT_MAX;
        while(!tmpStk.empty()){
            minEle = min(minEle,tmpStk.top());
            tmpStk.pop();
        }
        return minEle;
    }
};
