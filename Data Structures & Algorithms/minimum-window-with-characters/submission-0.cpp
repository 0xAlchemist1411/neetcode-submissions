class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t){
            return t;
        }
        int n = s.length();
        string ans = "";
        int minLength = INT_MAX;

        auto containsAll = [&](string str) {
            vector<int> freqT(128, 0), freqS(128, 0);
            for (char c : t) freqT[c]++;
            for (char c : str) freqS[c]++;
            for (int i = 0; i < 128; i++) {
                if (freqS[i] < freqT[i]) return false;
            }
            return true;
        };

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string str = s.substr(i,j-i+1);
                if(containsAll(str) and str.length() < minLength){
                    minLength = str.length();
                    ans = str;
                }
            }
        }

        return ans;
    }
};
