class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0, t, temp;
        for(auto n: nums)
            st.insert(n);
        for(auto n: nums){
            if(!st.count(n-1)){
                t = n + 1;  temp = 1;
                while(st.count(t)){
                    temp++;
                    t++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
