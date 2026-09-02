class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int pro = 1, zeros = 0;
        for(auto n: nums){
            if(n == 0)
                zeros++;
            else
                pro *= n;
            if(zeros > 1)
                return ans;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                ans[i] = pro;
            else
                ans[i] = (zeros==1)? 0: pro / nums[i];
        }
        return ans;
    }
};
