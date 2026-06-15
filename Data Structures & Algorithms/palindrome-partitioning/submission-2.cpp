class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> res;

        dfs(0, 0, s, ans, res);
        return res;
    }

    void dfs(int l, int r, string &s, vector<string> &ans, vector<vector<string>> &res){
        if(r >= s.size()){
            if(l == r){
                res.push_back(ans);
            }

            return;
        }

        if(isPalindrom(s, l, r)){
            ans.push_back(s.substr(l, r-l+1));
            dfs(r+1, r+1, s, ans, res); // start from new character for new string
            ans.pop_back();
        }

        dfs(l, r+1, s, ans, res);
    }

    bool isPalindrom(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

};
