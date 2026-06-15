class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }

        vector<pair<int,int>> vec(map.begin(),map.end());

        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // desending order by freq.
        });

        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(vec[i].first);
        }

        return res;
    }
};
