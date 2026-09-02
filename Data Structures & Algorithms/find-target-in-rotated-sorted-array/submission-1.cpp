class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target)
                return mid;
            else if((target>nums[mid]) ^ (target<nums[l]) ^ (nums[l]>nums[mid]))
                l = mid + 1;
            else
                r = mid - 1;
            // cout << l << " " << r << endl;
        }
        return -1;
    }
};
