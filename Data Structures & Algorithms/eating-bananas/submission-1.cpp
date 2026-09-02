class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int l = 1, r = piles[n-1], mid, ans = piles[n-1], hr;
        while(l <= r){
            mid = l + (r - l) / 2;
            hr = 0;
            for(auto p: piles)
                hr += ceil((double)p / mid);
            if(hr>0 && hr<=h){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
