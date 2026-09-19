class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> fq(256, 0);
        int l = 0, ans = 0;
        for(int i=0; i<s.size(); i++){
            fq[s[i]]++;
            while(fq[s[i]] > 1){
                fq[s[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
