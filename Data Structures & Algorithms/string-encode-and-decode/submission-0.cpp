class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto& str : strs) {
            encoded += str + "|";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|') {
                decoded.push_back(str);
                str = "";
            } else {
                str += s[i];
            }
        }
        return decoded;
    }
};
