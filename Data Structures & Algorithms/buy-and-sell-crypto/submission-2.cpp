class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int maxProfit = 0;
        int minBuy = p[0];

        for(int& sell: p){
            maxProfit = max(maxProfit, sell - minBuy);
            minBuy = min(minBuy, sell);
        }


        return maxProfit;
    }
};
