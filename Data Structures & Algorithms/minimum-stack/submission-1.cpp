class MinStack {
public:
    stack<pair<int, int> > minStack;
    int minVal = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        minVal = min(minVal, val);
        minStack.push({val, minVal});
    }
    
    void pop() {
        minStack.pop();
        minVal = minStack.empty()?INT_MAX:getMin();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};
