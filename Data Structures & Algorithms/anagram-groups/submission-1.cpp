class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        string t;
        for(auto s: strs){
            t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for(auto k: mp)
            ans.push_back(k.second);
        return ans;
    }
};
