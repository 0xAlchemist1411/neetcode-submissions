class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        vector<int> map1(26,0);
        for (char c : s1) {
            map1[c - 'a']++;
        }

        vector<int> map2(26,0);
        for (int i=0;i<s1.length();i++) {
            map2[s2[i] - 'a']++;
        }

        int left = 0;
        for (int right = s1.length(); right <= s2.length(); right++) {
            // Check current window
            if (map1 == map2) return true;

            if (right < s2.length()) {
                // Add next char to window
                map2[s2[right] - 'a']++;
                // Remove leftmost char from window
                map2[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};
