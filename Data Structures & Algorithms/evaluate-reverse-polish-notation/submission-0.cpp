class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a, b;
        stack<int> st;
        for(auto t: tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                b = st.top();   st.pop();
                a = st.top();   st.pop();
                if(t == "+")
                    st.push(a + b);
                else if(t == "-")
                    st.push(a - b);
                else if(t == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
            else
                st.push(stoi(t));
        }
        return st.top();
    }
};
