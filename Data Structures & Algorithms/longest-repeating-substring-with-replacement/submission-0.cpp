class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> fq(256, 0);
        int l = 0, mx = 0, ans = 1;
        for(int i=0; i<s.size(); i++){
            fq[s[i]]++;
            mx = max(mx, fq[s[i]]);
            while(i-l-mx+1 > k){
                fq[s[l]]--;
                l++;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
