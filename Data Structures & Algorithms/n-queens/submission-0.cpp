class Solution {
public:
    bool isValid(string t, int y, vector<string>& temp){
        int x = temp.size(), d;
        for(int i=0; i<temp.size(); i++){
            d = temp[i].find("Q");
            if(d == y || abs(x-i) == abs(y-d))
                return false;
        }
        return true;
    }
    void helper(int n, vector<string>& temp, vector<vector<string>>& ans, string& s){
        if(n == 0){
            ans.push_back(temp);
            return;
        }
        string t = s;
        for(int i=0; i<t.size(); i++){
            t[i] = 'Q';
            if(isValid(t, i, temp)){
                temp.push_back(t);
                helper(n-1, temp, ans, s);
                temp.pop_back();
            }
            t[i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        string s = "";
        for(int i=0; i<n; i++)
            s += '.';
        helper(n, temp, ans, s);
        return ans;
    }
};
