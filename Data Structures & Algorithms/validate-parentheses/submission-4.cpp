class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(auto c: s){
            if(c==')' || c=='}' || c==']'){
                if(q.empty())
                    return false;
                if((c==')' && q.top()=='(') || (c==']' && q.top()=='[') || (c=='}' && q.top()=='{')){
                    q.pop();
                }
                else
                    return false;
            }
            else
                q.push(c);
        }
        return q.empty();
    }
};
