class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& temp, set<vector<int>>& ans){
        ans.insert(temp);
        if(temp.size() == nums.size())
            return;
        for(; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(0, nums, temp, ans);
        for(auto st: ans)
            result.push_back(st);
        return result;
    }
};
