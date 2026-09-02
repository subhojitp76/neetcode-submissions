class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int f, r, target, sum;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            target = -nums[i];
            f = i+1;    r = nums.size()-1;
            while(f < r){
                sum = nums[f] + nums[r];
                if(sum > target)
                    r--;
                else if(sum < target)
                    f++;
                else{
                    vector<int> temp = {nums[i], nums[f], nums[r]};
                    ans.push_back(temp);
                    while(f<r && nums[f]==temp[1])
                        f++;
                    while(r>f && nums[r]==temp[2])
                        r--;
                }
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};
