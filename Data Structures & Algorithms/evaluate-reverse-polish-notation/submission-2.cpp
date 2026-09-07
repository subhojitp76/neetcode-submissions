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
                    a += b;
                else if(t == "*")
                    a *= b;
                else if(t == "-")
                    a -= b;
                else
                    a /= b;
                st.push(a);
            }
            else
                st.push(stoi(t));
        }
        return st.top();
    }
};
