class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        for(; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(i+1, nums, temp, ans);
            temp.pop_back();
        }
        ans.push_back(temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(i+1, nums, temp, ans);
            temp.pop_back();
        }
        return ans;
    }
};
