class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int, int>> st;
        pair<int, int> t;
        int ans = 0, k;
        st.push({h[0], 0});
        for(int i=1; i<h.size(); i++){
            t = {h[i], i};
            while(!st.empty() && st.top().first>h[i]){
                t.second = st.top().second;
                k = st.top().first * (i - st.top().second);
                ans = max(ans, k);
                st.pop();
            }
            if(!st.empty() && st.top().first==h[i]){
                t = st.top();
            }
            st.push(t);
        }
        while(!st.empty()){
            k = st.top().first * (h.size() - st.top().second);
            ans = max(ans, k);
            st.pop();
        }
        return ans;
    }
};
