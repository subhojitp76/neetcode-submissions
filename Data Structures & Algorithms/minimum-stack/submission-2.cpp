class MinStack {
public:
    stack<int> minS;
    MinStack() {
        minS = {};
    }
    
    void push(int val) {
        minS.push(val);
    }
    
    void pop() {
        if(!minS.empty()){
            minS.pop();
        }
    }
    
    int top() {
        return minS.top();
    }
    
    int getMin() {
        stack<int> temp = minS;
        int ans = INT_MAX;
        while(!temp.empty()){
            ans = min(ans, temp.top());
            temp.pop();
        }
        return ans;
    }
};
