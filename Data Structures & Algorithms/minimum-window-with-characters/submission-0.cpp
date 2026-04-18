class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char,int> need, have;
        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char c = s[right];
            have[c]++;
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                have[d]--;
                if (need.count(d) && have[d] < need[d]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
