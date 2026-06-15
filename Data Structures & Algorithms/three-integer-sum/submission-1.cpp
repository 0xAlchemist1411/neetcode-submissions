class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        ans.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
