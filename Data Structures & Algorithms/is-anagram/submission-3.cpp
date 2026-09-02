class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fq_s(26, 0), fq_t(26, 0);
        for(auto c: s){
            fq_s[c-'a']++;
        }
        for(auto c: t){
            fq_t[c-'a']++;
        }
        for(int i=0; i<26; i++){
            if(fq_s[i] != fq_t[i])
                return false;
        }
        return true;
    }
};
