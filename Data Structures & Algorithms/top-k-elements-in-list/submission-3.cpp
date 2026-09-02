class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i: nums)
            mp[i]++;
        priority_queue<pair<int, int>> pq;
        for(auto m: mp)
            pq.push({m.second, m.first});
        while(ans.size() < k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
