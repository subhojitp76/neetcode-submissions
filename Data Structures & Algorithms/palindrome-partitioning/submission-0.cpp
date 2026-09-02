class Solution {
public:
    bool isPalindrome(string s){
        int l=0, r=s.size()-1;
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;    r--;
        }
        return true;
    }
    void helper(int c, string& s, vector<vector<string>>& ans, vector<string>& temp){
        if(c == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=1; i<=s.size()-c; i++){
            if(!isPalindrome(s.substr(c, i)))
                continue;
            temp.push_back(s.substr(c, i));
            helper(c+i, s, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0, s, ans, temp);
        return ans;
    }
};
