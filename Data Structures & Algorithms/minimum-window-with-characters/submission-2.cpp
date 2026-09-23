class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        int left = 0, count1 = 0, count2 = 0;
        vector<int> fq1(256, 0), fq2(256, 0);
        for(auto c: t){
            fq1[c]++;
            if(fq1[c] == 1)
                count1++;
        }
        pair<int, int> sub = {0, 0};
        int l = INT_MAX;
        for(int i=0; i<s.size(); i++){
            fq2[s[i]]++;
            if(fq2[s[i]] == fq1[s[i]])
                count2++;
            while(count2 == count1){
                if(i-left < l){
                    l = i - left + 1;
                    sub = {left, l};
                }
                fq2[s[left]]--;
                if(fq2[s[left]] < fq1[s[left]])
                    count2--;
                left++;
            }
        }
        return s.substr(sub.first, sub.second);
    }
};
