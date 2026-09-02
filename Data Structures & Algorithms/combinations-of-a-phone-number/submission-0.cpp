class Solution {
public:
    unordered_map<char, string> let = {{'2', "abc"}, {'3', "def"},
                            {'4', "ghi"}, {'5', "jkl"},
                            {'6', "mno"}, {'7', "pqrs"},
                            {'8', "tuv"}, {'9', "wxyz"}};
    void helper(int i, string& digits, string str, vector<string>& ans){
        if(i == digits.size()){
            if(str.size() > 0)
                ans.push_back(str);
            return;
        }
        for(auto c: let[digits[i]]){
            helper(i+1, digits, str+c, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        helper(0, digits, "", ans);
        return ans;
    }
};