class MinStack {
public:
    vector<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        int minE = val;
        if(!st.empty())
            minE = min(minE, st.back().second);
        st.push_back({val, minE});
    }
    
    void pop() {
        if(!st.empty())
            st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
