class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> ans(temp.size(), 0);
        st.push({temp[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top().first<=temp[i])
                st.pop();
            if(!st.empty())
                ans[i] = st.top().second - i;
            st.push({temp[i], i});
        }
        return ans;
    }
};
