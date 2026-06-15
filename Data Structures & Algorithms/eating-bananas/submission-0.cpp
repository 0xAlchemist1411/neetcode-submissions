class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxEl = *max_element(piles.begin(), piles.end());
        int l = 1;
        int r = maxEl;
        int k = r;

        while(l <= r){
            int mid = l + (r-l)/2;
            long long tt = 0;
            for(int p: piles){
                tt += ceil(static_cast<double>(p)/mid);
            }

            if(tt <= h){ //favourable condition
                k = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};
