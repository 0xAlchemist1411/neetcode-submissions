class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                break;
            }
            else if(i > 0 and nums[i] == nums[i-1]){
                continue;
            }

            int low = i+1;
            int high = n-1;

            while(low < high){
                int sum = nums[i]+nums[low]+nums[high];
                if(sum == 0){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low < high and nums[low] == nums[low-1]){
                        low++;
                    }
                    while(low < high and nums[high] == nums[high+1]){
                        high--;
                    }
                }
                else if(sum < 0){
                    low++;
                }
                else{
                    high--;
                }
            }
        }

        return ans;
    }
};