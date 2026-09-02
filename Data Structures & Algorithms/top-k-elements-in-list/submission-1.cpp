class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;
        for(auto n: nums)
            mp[n]++;
        priority_queue<vector<int>> q;
        for(auto m: mp)
            q.push({m.second, m.first});
        for(; k>0 && !q.empty(); k--){
            ans.push_back(q.top()[1]);
            q.pop();
        }
        return ans;
    }
};
