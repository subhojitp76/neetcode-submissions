class Solution {
public:
    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        int t;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == INT_MIN)
                continue;
            t = nums[i];    nums[i] = INT_MIN;
            temp.push_back(t);
            helper(nums, temp, ans);
            temp.pop_back();
            nums[i] = t;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, temp, ans);
        return ans;
    }
};
