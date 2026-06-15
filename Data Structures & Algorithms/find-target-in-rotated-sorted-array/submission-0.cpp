class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[l] <= nums[mid]){
                if(nums[l] <= target and target < nums[mid]){ // target lies in left half
                    r = mid-1;
                }
                else{
                    l = mid+1; // target lies in right half
                }
            }
            else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;  // target lies in right half
                } else {
                    r = mid - 1;  // target lies in left half
                }
            }
        }

        return -1;
    }
};
