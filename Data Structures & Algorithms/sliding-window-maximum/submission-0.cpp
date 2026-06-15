class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<=n - k;i++){
            int maxVal = INT_MIN;
            for(int j=i;j<k+i;j++){
                maxVal = max(maxVal, nums[j]);
            }
            ans.push_back(maxVal);
        }

        return ans;
    }
};