class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        queue<vector<int>> q;
        priority_queue<vector<int>> pq;
        for(auto t: tasks)
            mp[t]++;
        for(auto m: mp)
            pq.push({m.second, 0});
        int ans = 0;
        while(!pq.empty() || !q.empty()){
            while(!q.empty() && ans>=q.front()[1]){
                pq.push(q.front());
                q.pop();
            }
            if(!pq.empty()){
                auto t = pq.top();    pq.pop();
                ans = max(ans, t[1]);
                if(t[0]-1 > 0)
                    q.push({t[0]-1, ans+n+1});
            }
            ans++;
        }
        return ans;
    }
};