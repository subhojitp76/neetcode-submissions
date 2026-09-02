class Solution {
public:
    vector<string> ans;
    void helper(string str, int opn, int cls){
        if(opn == 0){
            while(cls--)
                str += ')';
            ans.push_back(str);
            return;
        }
        helper(str+'(', opn-1, cls);
        if(cls > opn)
            helper(str+')', opn, cls-1);
    }
    vector<string> generateParenthesis(int n) {
        helper("", n, n);
        return ans;
    }
};
