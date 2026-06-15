class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> res;

        dfs(0, 0, s, ans, res);
        return res;
    }

    void dfs(int i, int j, string &s, vector<string> &ans, vector<vector<string>> &res){
        if(i >= s.size()){
            if(i == j){
                res.push_back(ans);
            }

            return;
        }

        if(isPalindrom(s, j, i)){
            ans.push_back(s.substr(j, i-j+1));
            dfs(i+1, i+1, s, ans, res);
            ans.pop_back();
        }

        dfs(i+1, j, s, ans, res);
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
