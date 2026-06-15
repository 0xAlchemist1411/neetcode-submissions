class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int maxArea = 0;
        int i = 0;
        int j = n-1;

        while(i < j){
            int b = j-i;
            int l = min(h[j],h[i]);
            int area = l*b;
            if(area > maxArea){
                maxArea = area;
            }
            if(h[i] < h[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxArea;
    }
};
