class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        for(auto t: tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                a = st.top();   st.pop();
                b = st.top();   st.pop();
                if(t == "+")
                    st.push(a + b);
                else if(t == "*")
                    st.push(a * b);
                else if(t =="-")
                    st.push(b - a);
                else
                    st.push(b / a);
            }
            else
                st.push(stoi(t));
        }
        return st.top();
    }
};
