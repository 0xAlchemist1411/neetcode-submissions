class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        unordered_map<char,int> mp;
        int l = 0;
        int maxfreq = 0;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            maxfreq = max(maxfreq, mp[s[i]]);
            
            if(i-l+1 - maxfreq > k){
                mp[s[l]]--;
                l++;
            }
            
            ans = max(ans,i-l+1);
        }

        return ans;
    }
};
