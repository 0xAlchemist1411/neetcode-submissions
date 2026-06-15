class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto i: nums){
            count[i]++;
        }

        // priority_queue<pair<int,int>> pq; // maxHeap;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto& i: count){
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> res;
        for(int i=0;i<k;i++){
            int val = minHeap.top().second;
            minHeap.pop();
            res.push_back(val);
        }

        return res;
    }
};
