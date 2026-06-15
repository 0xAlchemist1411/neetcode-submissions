class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int maxProfit = 0;
        int l = 0, r = 1;
        
        while(r < n){
            if(p[l] < p[r]){
                int profit = p[r] - p[l];
                maxProfit = max(profit, maxProfit);
            }
            else{
                l = r;
            }

            r++;
        }


        return maxProfit;
    }
};
