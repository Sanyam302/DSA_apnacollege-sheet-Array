class Solution {
public:
    string expandFromCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string longest = s.substr(0, 1); // single char is always palindrome

        for (int i = 0; i < s.size(); ++i) {
            // Odd length
            string odd = expandFromCenter(s, i, i);
            if (odd.size() > longest.size()) longest = odd;

            // Even length
            string even = expandFromCenter(s, i, i + 1);
            if (even.size() > longest.size()) longest = even;
        }
        return longest;
    }
};
