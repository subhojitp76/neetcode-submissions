class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int target){
        if(target == 0)
            ans.push_back(temp);
        else if(target < 0)
            return;
        for(; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(i+1, nums, temp, ans, target-nums[i]);
            temp.pop_back();
            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, temp, ans, target);
        return ans;
    }
};
