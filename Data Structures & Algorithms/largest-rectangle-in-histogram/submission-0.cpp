class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int maxArea = 0;

        for(int i=0;i<n;i++){
            int minHeight = INT_MAX;
            for(int j=i;j<n;j++){
                int l = j - i + 1;
                minHeight = min(minHeight,h[j]);

                int area = l * minHeight;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

