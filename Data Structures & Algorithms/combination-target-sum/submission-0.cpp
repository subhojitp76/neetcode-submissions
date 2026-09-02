class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int target){
        if(target == 0)
            ans.push_back(temp);
        else if(target < 0)
            return;
        for(; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(i, nums, temp, ans, target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(i, nums, temp, ans, target-nums[i]);
            temp.pop_back();
        }
        return ans;
    }
};
