class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int area = 0, n = heights.size();
        for(int i=0; i<n; i++){
            int t = i;
            while(!st.empty() && st.top().first>=heights[i]){
                auto temp = st.top();   st.pop();
                area = max(area, temp.first * (i - temp.second));
                t = temp.second;
            }
            st.push({heights[i], t});
        }
        while(!st.empty()){
            auto temp = st.top();   st.pop();
            area = max(area, temp.first * (n - temp.second));
        }
        return area;
    }
};
