class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            if(mp[i])
                return true;
            mp[i] = 1;
        }
        return false;
    }
};
