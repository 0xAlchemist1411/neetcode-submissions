class Solution {
public:
    string minWindow(string s, string t) {
        int hash[128] = {0};
        int n = s.length();
        int m = t.length();
        if(n==0 or m==0){
            return "";
        }

        for(auto &c: t){
            hash[c]++;
        }

        int l = 0, r = 0, cnt = 0, minLen = INT_MAX, idx = -1;

        while(r < n){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    idx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }

            r++;
        }


        return idx == -1 ? "" : s.substr(idx, minLen);
    }
};
