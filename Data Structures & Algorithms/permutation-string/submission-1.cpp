class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> fq1(256, 0), fq2(256, 0);
        for(auto i: s1)
            fq1[i]++;
        int l = 0;
        for(int r=0; r<s2.size(); r++){
            fq2[s2[r]]++;
            while(fq2[s2[r]] > fq1[s2[r]]){
                fq2[s2[l]]--;
                l++;
            }
            if(fq1 == fq2)
                return true;
        }
        return false;
    }
};
