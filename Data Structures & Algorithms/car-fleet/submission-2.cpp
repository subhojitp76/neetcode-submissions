class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 1;
        double t;
        priority_queue<pair<int, double>> pq;
        for(int i=0; i<position.size(); i++){
            t = (double)((double)(target - position[i]) / speed[i]);
            // cout << t << endl;
            pq.push({position[i], t});
        }
        t = pq.top().second;
        pq.pop();
        while(!pq.empty()){
            if(pq.top().second > t){
                fleet++;
                t = pq.top().second;
            }
            pq.pop();
        }
        return fleet;
    }
};
