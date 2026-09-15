class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=nums.size()-1; i>0; i--){
            int l = 0, r = i-1, t = nums[i] * (-1);
            while(l < r){
                if(nums[l]+nums[r] == t){
                    ans.push_back({nums[l++], nums[r--], nums[i]});
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else if(nums[l]+nums[r] > t)
                    r--;
                else
                    l++;
            }
            while(i>1 && nums[i]==nums[i-1])
                i--;
        }
        return ans;
    }
};
