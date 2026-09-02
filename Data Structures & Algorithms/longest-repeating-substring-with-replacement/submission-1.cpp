class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> fq(256, 0);
        int left = 0, mx = 0, ans = 0;
        for(int i=0; i<s.size(); i++){
            fq[s[i]]++;
            mx = max(mx, fq[s[i]]);
            while(i-left-mx+1 > k){
                fq[s[left]]--;
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};
