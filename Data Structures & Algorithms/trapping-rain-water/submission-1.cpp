class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if(n == 0){
            return 0;
        }

        int res = 0;
        int i = 0;
        int j = n-1;
        int leftmax = h[i];
        int rightmax = h[j];

        while(i < j){
            if(leftmax < rightmax){
                i++;
                leftmax = max(leftmax, h[i]);
                res += leftmax - h[i];
            }
            else{
                j--;
                rightmax = max(rightmax, h[j]);
                res += rightmax - h[j];
            }
        }

        return res;
    }
};
