class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans;
        int n = t.size();

        for(int i=0;i<n;i++){
            int day = 0;
            for(int j=i+1;j<n;j++){
                if(t[j] > t[i]){
                    day = j-i;
                    break;
                }
            }
            ans.push_back(day);
        }

        return ans;
    }
};
