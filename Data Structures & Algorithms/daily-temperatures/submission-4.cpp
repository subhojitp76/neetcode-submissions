class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> days(n, 0);
        stack<pair<int, int>> st;
        st.push({temp[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top().first<=temp[i])
                st.pop();
            if(!st.empty())
                days[i] = st.top().second - i;
            st.push({temp[i], i});
        }
        return days;
    }
};
