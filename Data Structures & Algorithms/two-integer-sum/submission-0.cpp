class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            map[nums[i]] = i;
        }


        for(int i=0;i<nums.size();i++){
            int dif = target - nums[i];
            if(map.count(dif) and map[dif] != i){
                return {i, map[dif]};
            }
        }

        return {};
    }
};
