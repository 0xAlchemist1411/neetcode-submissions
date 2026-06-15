class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int res = 0;
        unordered_set<int> temp(nums.begin(),nums.end());

        for(int i: nums){
            int streak = 0;
            if(!temp.count(i-1)){
                int length = 1;
                while(temp.count(i+1)){
                    length++;
                    i++;
                }

                res = max(res,length);
            }
        }

        return res;
    }
};


