class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        vector<int> ltor(n, 0), rtol(n, 0);
        ltor[0] = h[0];
        rtol[n-1] = h[n-1];
        for(int i=1; i<n-1; i++){
            ltor[i] = max(ltor[i-1], h[i]);
            rtol[n-1-i] = max(rtol[n-i], h[n-1-i]);
        }
        for(int i=1; i<n-1; i++){
            ans += (min(ltor[i], rtol[i]) - h[i]);
        }
        return ans;
    }
};
