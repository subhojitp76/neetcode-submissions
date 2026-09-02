class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto i: strs){
            ans += i;
            ans += '~';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0; i<s.size(); i++){
            string t = "";
            while(s[i] != '~')
                t += s[i++];
            ans.push_back(t);
        }
        return ans;
    }
};
