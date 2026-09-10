class MinStack {
public:
    stack<pair<int, int>> minSt;
    MinStack() {
        minSt = {};
    }
    
    void push(int val) {
        int t = val;
        if(!minSt.empty())
            t = min(t, minSt.top().second);
        minSt.push({val, t});
    }
    
    void pop() {
        minSt.pop();
    }
    
    int top() {
        return minSt.top().first;
    }
    
    int getMin() {
        return minSt.top().second;
    }
};
