class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        int have = 0, need = 0;
        vector<int> fqs(128, 0), fqt(128, 0);
        for(auto i: t){
            fqt[i]++;
            if(fqt[i] == 1)
                need++;
        }
        int l = 0, r = 0, ans = INT_MAX, al = -1, ar = s.size();
        while(l < s.size()){
            if(r < s.size()){
                fqs[s[r]]++;
                if(fqs[s[r]] == fqt[s[r]])
                    have++;
                r++;
            }
            else if(have < need)
                break;
            while(have == need){
                if(r-l < ans){
                    ans = r - l;
                    al = l;
                }
                fqs[s[l++]]--;
                if(fqt[s[l-1]] > fqs[s[l-1]]){
                    have--;
                    break;
                }
            }
        }
        if(al == -1)
            return "";
        return s.substr(al, ans);
    }
};