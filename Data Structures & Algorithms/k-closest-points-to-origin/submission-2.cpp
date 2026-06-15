class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min heap -> {distance, {x, y}}
        priority_queue<pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > minHeap;

        // Push all points with their squared distance
        for (auto &p : points) {
            int x = p[0];
            int y = p[1];
            int dist = x * x + y * y;  // squared distance
            minHeap.push({dist, p});
        }

        vector<vector<int>> ans;

        // Extract k closest points
        while (k--) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
