class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int tfreq[128] = {0};
        int sfreq[128] = {0};
        int required = 0; // unique chars in t

        // Count frequencies in t and number of unique chars
        for (char c : t) {
            if (tfreq[c] == 0) required++;
            tfreq[c]++;
        }

        int formed = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.size()) {
            char c = s[right];
            sfreq[c]++;

            // Check if this char frequency matches required freq
            if (tfreq[c] != 0 && sfreq[c] == tfreq[c]) {
                formed++;
            }

            // Shrink window while valid
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char leftChar = s[left];
                sfreq[leftChar]--;
                if (tfreq[leftChar] != 0 && sfreq[leftChar] < tfreq[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
