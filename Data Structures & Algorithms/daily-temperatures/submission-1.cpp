class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n,0);
        stack<pair<int, int>> stk;

        for(int i=0;i<n;i++){
            int temp = t[i];
            while(!stk.empty() && temp > stk.top().first) {
                auto pair = stk.top();
                stk.pop();
                ans[pair.second] = i - pair.second;
            }

            stk.push({temp,i});
        }

        return ans;
    }
};
