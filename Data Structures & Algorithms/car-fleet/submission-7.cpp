class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, double>> st;
        for(int i=0; i<speed.size(); i++){
            double t = (double)((double)(target - position[i]) / speed[i]);
            st.push({position[i], t});
        }
        int groups = 0;
        while(!st.empty()){
            groups++;
            double t = st.top().second;    st.pop();
            while(!st.empty() && st.top().second<=t)
                st.pop();
        }
        return groups;
    }
};
