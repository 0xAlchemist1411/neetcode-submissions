class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map for characters in t
        // hash[c] > 0 means we still need that character
        int hash[128] = {0};

        int n = s.length();
        int m = t.length();
        
        // Edge case: if either string is empty, return ""
        if (n == 0 || m == 0) {
            return "";
        }

        // Fill frequency map with counts of characters in t
        for (auto &c : t) {
            hash[c]++;
        }

        // Sliding window pointers
        int l = 0, r = 0;
        // cnt = number of characters from t matched so far
        int cnt = 0;
        // minLen = length of smallest valid window found so far
        int minLen = INT_MAX;
        // idx = start index of smallest valid window
        int idx = -1;

        // Expand the right pointer
        while (r < n) {
            // If current char is still needed, increase match count
            if (hash[s[r]] > 0) {
                cnt++;
            }
            // Decrease the count for current char (can go negative if extra)
            hash[s[r]]--;

            // When we have matched all m characters of t
            while (cnt == m) {
                // Update smallest window if current one is smaller
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    idx = l;
                }
                // Shrink from left
                hash[s[l]]++;
                // If char at l is now needed again, reduce matched count
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++; // move left pointer forward
            }

            r++; // move right pointer forward
        }

        // If no valid window found, return ""
        return idx == -1 ? "" : s.substr(idx, minLen);
    }
};
