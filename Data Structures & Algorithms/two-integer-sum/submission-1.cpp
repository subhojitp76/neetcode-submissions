class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            // cout << (tar-nums[i]) << " ";
            if(mp[tar-nums[i]] > 0)
                return {mp[tar-nums[i]]-1, i};
            mp[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};
