class Solution {
private:
    void dfs(int idx, vector<int> &nums, vector<int> &subset, vector<vector<int>> &res){
        res.push_back(subset);
            
        for(int i=idx;i<nums.size();i++){
            // Skip duplicates at the same level
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }

            subset.push_back(nums[i]);
            dfs(i+1, nums, subset, res);
            subset.pop_back();
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        dfs(0, nums, subset, res);
        return res;
    }
};