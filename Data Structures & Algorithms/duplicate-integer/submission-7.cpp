class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto n: nums){
            if(mp[n])
                return true;
            mp[n] = 1;
        }
        return false;
    }
};