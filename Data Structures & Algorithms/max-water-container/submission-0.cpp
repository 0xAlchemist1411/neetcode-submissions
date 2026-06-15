class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int l = min(h[i],h[j]);
                int b = j - i;
                int area = l*b;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
