class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> fq1(26, 0), fq2(26, 0);
        for(auto c: s1)
            fq1[c-'a']++;
        int l = 0;
        for(int i=0; i<s2.size(); i++){
            fq2[s2[i]-'a']++;
            while(fq2[s2[i]-'a'] > fq1[s2[i]-'a']){
                fq2[s2[l]-'a']--;
                l++;
            }
            if(fq1 == fq2)
                return true;
        }
        return false;
    }
};
