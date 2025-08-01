class Solution {
public:
    bool isPalindrome(string s) {
int a = 0;
        int e = s.length() - 1;
        while (a < e) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[a])) {
                a++;
                continue;
            }
            if (!isalnum(s[e])) {
                e--;
                continue;
            }

            // Compare characters (case insensitive)
            if (tolower(s[a]) != tolower(s[e])) {
                return false;
            }

            // Move pointers inward
            a++;
            e--;
        }
        return true;
    }
};