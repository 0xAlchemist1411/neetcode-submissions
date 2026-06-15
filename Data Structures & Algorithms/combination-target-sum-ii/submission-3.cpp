class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // IMPORTANT
        vector<vector<int>> res;
        vector<int> path;

        dfs(0, nums, target, path, res);
        return res;
    }

    void dfs(int index, vector<int>& nums, int target,
             vector<int>& path, vector<vector<int>>& res) {

        // Base case
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Pruning
            if (nums[i] > target) break;

            path.push_back(nums[i]);
            dfs(i + 1, nums, target - nums[i], path, res);
            path.pop_back();
        }
    }
};
