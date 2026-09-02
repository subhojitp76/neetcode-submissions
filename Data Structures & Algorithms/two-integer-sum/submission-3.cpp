class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int t;
        for(int i=0; i<nums.size(); i++){
            t = target - nums[i];
            if(mp.contains(t)){
                return {mp[t] - 1, i};
            }
            mp[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};
