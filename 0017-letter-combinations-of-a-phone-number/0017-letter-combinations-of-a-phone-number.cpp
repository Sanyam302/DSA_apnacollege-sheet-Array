class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> str(10);
        int a = 97;
        for (int i = 2; i <= 9; i++) {
            int letters = (i == 7 || i == 9) ? 4 : 3;
            for (int j = 0; j < letters; j++) {
                str[i] += char(a++);
            }
        }

        vector<string> result = {""};

        for (char ch : digits) {
            vector<string> temp;
            string letters = str[ch - '0'];
            for (string prefix : result) {
                for (char c : letters) {
                    temp.push_back(prefix + c);
                }
            }
            result = temp;
        }
        return result;
    }
};
