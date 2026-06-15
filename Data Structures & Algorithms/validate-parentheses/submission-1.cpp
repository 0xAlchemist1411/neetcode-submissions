class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> mp;
        mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c: s){
            if(mp.count(c)){
                if(!stack.empty() and stack.top() == mp[c]){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                stack.push(c);
            }
        }

        return stack.empty();
    }
};