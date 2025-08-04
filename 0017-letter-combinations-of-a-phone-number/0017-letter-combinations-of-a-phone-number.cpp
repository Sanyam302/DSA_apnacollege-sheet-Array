class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> str(10);  // index 0 to 9

        int a = 97; // ASCII value of 'a'
        for (int i = 2; i <= 9; i++) {
            str[i] += char(a++);
            str[i] += char(a++);
            str[i] += char(a++);
            if (i == 7 || i == 9) {
                str[i] += char(a++);
            }
        }

        vector<string> result;
        result.push_back(""); // base for combinations

        for (char ch : digits) {
            vector<string> temp;
            string letters = str[ch - '0'];

            for (string prefix : result) {
                for (char letter : letters) {
                    temp.push_back(prefix + letter);
                }
            }

            result = temp;
        }

        return result;
    }
};
