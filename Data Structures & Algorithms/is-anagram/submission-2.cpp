class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> fq(255, 0);
        for(auto c: s)
            fq[c]++;
        for(auto c: t){
            fq[c]--;
            if(fq[c] < 0)
                return false;
        }
        return true;
    }
};
