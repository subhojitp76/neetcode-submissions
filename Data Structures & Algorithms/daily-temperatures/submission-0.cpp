class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<temp.size(); i++){
            while(!pq.empty() && pq.top().first<temp[i]){
                temp[pq.top().second] = i - pq.top().second;
                cout << pq.top().first << " " << temp[i] << " -> " << temp[pq.top().second] << endl;
                pq.pop();
            }
            pq.push({temp[i], i});
        }
        while(!pq.empty()){
            temp[pq.top().second] = 0;
            pq.pop();
        }
        return temp;
    }
};
