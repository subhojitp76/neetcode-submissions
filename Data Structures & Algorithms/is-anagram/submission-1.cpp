class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sc(30, 0), tc(30,0);
        for(auto i: s)
            sc[i-'a']++;
        for(auto i: t)
            tc[i-'a']++;
        return sc==tc;
    }
};
