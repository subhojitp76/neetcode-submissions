class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), m1 = 0, m2 = 0, ans = 0;
        vector<int> ltr(n), rtl(n);
        for(int i=0; i<n; i++){
            m1 = max(m1, height[i]);
            m2 = max(m2, height[n-1-i]);
            ltr[i] = m1;
            rtl[n-1-i] = m2;
        }
        for(int i=0; i<n; i++)
            ans += (min(ltr[i], rtl[i]) - height[i]);
        return ans;
    }
};
