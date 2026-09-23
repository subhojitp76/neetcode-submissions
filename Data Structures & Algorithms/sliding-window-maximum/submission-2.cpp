class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i=0; i<k-1; i++){
            while(!q.empty() && q.back()<nums[i])
                q.pop_back();
            q.push_back(nums[i]);
        }
        vector<int> ans;
        int left = 0;
        for(int i=k-1; i<nums.size(); i++){
            while(!q.empty() && q.back()<nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            ans.push_back(q.front());
            if(q.front() == nums[left])
                q.pop_front();
            left++;
        }
        return ans;
    }
};
