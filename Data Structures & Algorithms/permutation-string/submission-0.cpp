class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> mp1, mp2;

        // Build freq map for s1
        for (char c : s1)
            mp1[c]++;

        int k = s1.size();

        // Build first window in s2
        for (int i = 0; i < k; i++)
            mp2[s2[i]]++;

        if (mp1 == mp2) return true;

        // Slide the window
        for (int i = k; i < s2.size(); i++) {
            mp2[s2[i]]++;          // add new char
            mp2[s2[i - k]]--;      // remove old char

            // Clean up zero-frequency keys
            if (mp2[s2[i - k]] == 0)
                mp2.erase(s2[i - k]);

            if (mp1 == mp2)
                return true;
        }

        return false;
    }
};
