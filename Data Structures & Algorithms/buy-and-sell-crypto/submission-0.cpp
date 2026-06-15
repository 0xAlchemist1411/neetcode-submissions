class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int maxProfit = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int profit = p[j] - p[i];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};
