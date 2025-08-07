class Solution {
public:
    string longestPalindrome(string s) {
        // Step 1: Transform the string
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();
        vector<int> P(n, 0); // Radius of palindrome at each center
        int C = 0, R = 0;    // Center and right boundary of current palindrome
        int maxLen = 0, centerIndex = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * C - i;

            if (i < R)
                P[i] = min(R - i, P[mirror]);

            // Try to expand palindrome centered at i
            int a = i + (1 + P[i]), b = i - (1 + P[i]);
            while (a < n && b >= 0 && t[a] == t[b]) {
                P[i]++;
                a++;
                b--;
            }

            // Update center and right boundary if expanded past R
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            // Keep track of max length palindrome
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        // Extract the longest palindrome from the original string
        int start = (centerIndex - maxLen) / 2;  // Convert index in transformed string to original
        return s.substr(start, maxLen);
    }
};
