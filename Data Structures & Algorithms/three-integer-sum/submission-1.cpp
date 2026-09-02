class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-2; i++){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum > (-nums[i]))
                    r--;
                else if(sum < (-nums[i]))
                    l++;
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;    r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
            }
            while(i<nums.size()-1 && nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};
