class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto n: nums)
            st.insert(n);
        int ans = 0;
        for(auto n: nums){
            if(st.count(n-1))
                continue;
            else{
                int t = n + 1;
                while(st.count(t))
                    t++;
                ans = max(ans, t - n);
            }
        }
        return ans;
    }
};
