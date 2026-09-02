class Solution {
public:

    string encode(vector<string>& strs) {
        string coded = "";
        for(auto str: strs)
            coded += to_string(str.size()) + "#" + str;
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i=0; i<s.size(); i++){
            string temp = "";
            while(s[i] != '#')
                temp += s[i++];
            int t = stoi(temp);
            decoded.push_back(s.substr(i+1, t));
            i += t;
        }
        return decoded;
    }
};
