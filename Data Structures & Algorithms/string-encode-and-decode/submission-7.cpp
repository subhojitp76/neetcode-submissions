class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto s: strs){
            str += to_string(s.size()) + "#" + s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for(int i=0; i<s.size(); i++){
            string num = "";
            while(s[i] != '#')
                num += s[i++];
            int t = stoi(num);
            strs.push_back(s.substr(i+1, t));
            i += t;
        }
        return strs;
    }
};
