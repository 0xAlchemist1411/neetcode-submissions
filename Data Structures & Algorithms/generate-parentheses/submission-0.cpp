class Solution {
public:
    void backtrack(int open, int close, int n, string &ans, vector<string> &res){
        if(open == close and open == n){
            res.push_back(ans);
            return;
        }

        if(open < n){
            ans += '(';
            backtrack(open + 1, close, n, ans, res);
            ans.pop_back();
        }

        if(close < open){
            ans += ')';
            backtrack(open, close + 1, n, ans, res);
            ans.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> res;
        backtrack(0,0, n, ans, res);
        return res;
    }
};