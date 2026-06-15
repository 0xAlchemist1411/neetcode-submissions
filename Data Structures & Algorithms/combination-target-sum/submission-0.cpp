class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sums;

        dfs(0, nums, target, sums, res);
        return res;
    }

    void dfs(int i, vector<int>& nums, int target, vector<int> &sums, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(sums);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        sums.push_back(nums[i]);
        dfs(i, nums, target-nums[i], sums, res);

        sums.pop_back();
        dfs(i+1, nums, target, sums, res);
    }
};












