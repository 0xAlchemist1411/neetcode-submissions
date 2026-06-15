class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_set<int> temp(nums.begin(),nums.end());

        for(int i: nums){
            int streak = 0;
            int curr = i;
            while(temp.count(curr)){
                streak++;
                curr++;
            }
            res = max(res, streak);
        }

        return res;
    }
};







