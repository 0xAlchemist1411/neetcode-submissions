class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};

        for (int num : nums) {
            int size = res.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = res[i]; // add previously created subsets
                subset.push_back(num); // add new ones
                res.push_back(subset); // add subset to final res
            }
        }

        return res;
    }
};