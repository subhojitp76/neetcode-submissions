class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> rlmax(n), lrmin(n);
        lrmin[0] = prices[0];
        rlmax[n-1] = prices[n-1];
        for(int i=1; i<n; i++){
            lrmin[i] = min(lrmin[i-1], prices[i]);
            rlmax[n-1-i] = max(rlmax[n-i], prices[n-1-i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            // cout << rlmax[i] << " " << lrmin[i] << endl;
            ans = max(ans, rlmax[i]-lrmin[i]);
        }
        return ans;
    }
};
