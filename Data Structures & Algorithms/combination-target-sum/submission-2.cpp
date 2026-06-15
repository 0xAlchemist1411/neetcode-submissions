class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sums;

        dfs(0, nums, target, sums, res, 0);
        return res;
    }

    void dfs(int i, vector<int>& nums, int target, vector<int> &sums, vector<vector<int>> &res, int total){
        
        if(total == target){
            res.push_back(sums);
            return;
        }

        if(total > target || i >= nums.size()){
            return;
        }

        // try a nums
        sums.push_back(nums[i]);
        dfs(i, nums, target, sums, res, total + nums[i]);
        sums.pop_back();

        // move ahead 
        dfs(i+1, nums, target, sums, res, total);
    }
};

