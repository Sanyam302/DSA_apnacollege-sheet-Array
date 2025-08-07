class Solution {
public:
    unordered_set<int> visited;

    void maxlength(string s, string &ans, int mid) {
        if (mid < 0 || mid >= s.size() || visited.count(mid)) return;
        visited.insert(mid);

        // Odd
        int i = mid, j = mid;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            if (j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
            i--; j++;
        }

        // Even
        i = mid, j = mid + 1;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            if (j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
            i--; j++;
        }

        maxlength(s, ans, mid - 1);
        maxlength(s, ans, mid + 1);
    }

    string longestPalindrome(string s) {
        string ans = "";
        int mid = s.size() / 2;
        maxlength(s, ans, mid);
        return ans;
    }
};
// ✅ Don't forget this semicolon
