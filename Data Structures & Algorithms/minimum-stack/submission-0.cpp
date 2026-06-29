class MinStack {
public:
    stack<int> s;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ms.empty()){
            ms.push(val);
        } else {
            ms.push(min(ms.top(),val));
        }
    }
    
    void pop() {
        s.pop();
        ms.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
        
    }
};
