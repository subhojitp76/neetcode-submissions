class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int zeros = 0, pro = 1;
        for(auto n: nums){
            if(n == 0)
                zeros++;
            else
                pro *= n;
            if(zeros > 1)
                return ans;
        }
        for(int i=0; i<nums.size(); i++){
            ans[i] = (nums[i]==0? pro: (zeros>0? 0: pro/nums[i]));
        }
        return ans;
    }
};
