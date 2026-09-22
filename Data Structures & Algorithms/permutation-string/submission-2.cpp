class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        vector<int> fq1(256, 0), fq2(256, 0);
        for(auto c: s1)
            fq1[c]++;
        for(int i=0; i<s1.size()-1; i++)
            fq2[s2[i]]++;
        int l = 0;
        for(int i=s1.size()-1; i<s2.size(); i++){
            fq2[s2[i]]++;
            if(fq1 == fq2)
                return true;
            fq2[s2[l]]--;   l++;
        }
        return false;
    }
};
