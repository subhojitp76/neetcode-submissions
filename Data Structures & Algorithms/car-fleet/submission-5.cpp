class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        priority_queue<pair<int, double>> pq;
        double t;
        int n = speed.size(), ans = 0;
        for(int i=0; i<n; i++){
            t = (double)((double)(target - pos[i]) / speed[i]);
            pq.push({pos[i], t});
        }
        while(!pq.empty()){
            // cout << pq.top().first << " " << pq.top().second << endl;
            t = pq.top().second;    pq.pop();
            while(!pq.empty() && pq.top().second<=t)
                pq.pop();
            ans++;
        }
        return ans;
    }
};
