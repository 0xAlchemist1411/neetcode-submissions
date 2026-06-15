class Solution {
public:
    string minWindow(string s, string t) {
        // Array to store how many of each character we still need
        // Positive value means we need that many more
        // Zero or negative means we already have enough (or extra)
        int hash[128] = {0};

        int n = s.length();
        int m = t.length();

        // If either string is empty, there is no valid window
        if (n == 0 || m == 0) {
            return "";
        }

        // Fill the frequency array with counts of characters in t
        for (auto &c : t) {
            hash[c]++;
        }

        // Two pointers for the sliding window
        int l = 0, r = 0;
        // Number of characters from t that we have matched so far
        int cnt = 0;
        // Track the length of the smallest valid window found
        int minLen = INT_MAX;
        // Track the starting index of the smallest valid window
        int idx = -1;

        // Move the right pointer to expand the window
        while (r < n) {
            // If the current character is still needed, increase matched count
            if (hash[s[r]] > 0) {
                cnt++;
            }
            // Reduce the need count for this character
            // (can go negative if we have more than needed)
            hash[s[r]]--;

            // If we have matched all m characters from t
            while (cnt == m) {
                // Update result if this window is smaller than previous best
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    idx = l;
                }

                // Try to shrink the window from the left
                // Put the character at 'l' back into the "needed" pool
                hash[s[l]]++;
                // If this character is now needed again, window is no longer valid
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                // Move left pointer forward to shrink window
                l++;
            }

            // Move right pointer forward to expand window
            r++;
        }

        // If no valid window was found, return ""
        return idx == -1 ? "" : s.substr(idx, minLen);
    }
};
