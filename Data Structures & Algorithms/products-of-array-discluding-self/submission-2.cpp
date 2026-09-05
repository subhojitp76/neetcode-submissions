class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMul(n, 1), postMul(n, 1);
        for(int i=1; i<n; i++){
            preMul[i] = preMul[i-1] * nums[i-1];
            postMul[n-1-i] = postMul[n-i] * nums[n-i];
        }
        vector<int> ans(n);
        ans[0] = postMul[0];
        ans[n-1] = preMul[n-1];
        for(int i=1; i<n-1; i++){
            ans[i] = preMul[i] * postMul[i];
        }
        return ans;
    }
};
