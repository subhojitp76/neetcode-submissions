class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target>nums[mid] ^ target<nums[l] ^ nums[mid]<nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
