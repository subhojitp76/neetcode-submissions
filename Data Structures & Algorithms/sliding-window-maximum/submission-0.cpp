class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int l = 1, r = 0;
        for(; r<k; r++){
            pq.push({nums[r], r});
        }
        vector<int> ans = {pq.top().first};
        for(; r<nums.size(); r++, l++){
            pq.push({nums[r], r});
            while(pq.top().second < l)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
