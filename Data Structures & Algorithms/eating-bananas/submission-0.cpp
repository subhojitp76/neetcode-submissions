class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int mn = 1, mx = piles[n-1];
        int ans = mx, mid, t;
        while(mn <= mx){
            mid = mn + (mx - mn) / 2;
            t = 0;
            for(int i=0; i<n; i++){
                // cout << piles[i] << " : " << ceil((double)piles[i] / mid) << endl;
                t += ceil((double)piles[i] / mid);
            }
            // cout << mid << " " << t << endl;
            if(t > 0 && t <= h){
                ans = mid;
                mx = mid - 1;
            }
            else{
                mn = mid + 1;
            }
        }
        return ans;
    }
};
