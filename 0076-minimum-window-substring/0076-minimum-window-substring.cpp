class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> tfreq;
        for (char c : t) tfreq[c]++;
        
        unordered_map<char, int> windowCounts;
        int required = tfreq.size();  // number of unique chars to be matched
        int formed = 0;                // how many unique chars currently meet requirement
        
        int left = 0, right = 0;
        int minLen = INT_MAX, minStart = 0;
        
        while (right < s.size()) {
            char c = s[right];
            windowCounts[c]++;
            
            if (tfreq.find(c) != tfreq.end() && windowCounts[c] == tfreq[c]) {
                formed++;
            }
            
            // Try to shrink the window from the left if all chars matched
            while (left <= right && formed == required) {
                // Update answer if smaller window found
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Remove leftmost char from window
                char leftChar = s[left];
                windowCounts[leftChar]--;
                if (tfreq.find(leftChar) != tfreq.end() && windowCounts[leftChar] < tfreq[leftChar]) {
                    formed--;
                }
                left++;
            }
            
            right++;
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
