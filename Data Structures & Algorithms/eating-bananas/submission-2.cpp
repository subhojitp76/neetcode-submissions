class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minE = 1, maxE = INT_MIN, mid;
        for(auto p: piles){
            maxE = max(maxE, p);
        }
        int ans = INT_MAX, temp;
        while(minE <= maxE){
            mid = (minE + maxE) / 2;
            temp = 0;
            for(auto p: piles)
                temp += ceil((double)p / mid);
            cout << temp << endl;
            if(temp <= h){
                ans = mid;
                maxE = mid - 1;
            }
            else
                minE = mid + 1;
        }
        return ans;
    }
};
