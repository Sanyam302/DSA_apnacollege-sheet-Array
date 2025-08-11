
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        // Hash to store number of characters in t
        unordered_map<char, int> tHash;
        // Hash to store number of characters in s
        unordered_map<char, int> sHash;

        for (char i : t){
            tHash[i]++;
        }

        // Store needed characters in s
        int neededChars = t.size();

        int windowStart = 0;
        int windowEnd = 0;

        // To track min length from start
        int minLen = INT_MAX;
        // To track min starting point
        int minStart = 0;


        for (windowEnd = 0; windowEnd < s.size(); ++windowEnd) {
            
            // If after increasing in sHash, still it is less than or equal tHash
            // It determines we found that character, so decrease neededChars
            if(++sHash[s[windowEnd]] <= tHash[s[windowEnd]]){
                neededChars--;
            }


            // If neededChars is 0, then we can reduce from start
            while (neededChars == 0) {

                // To track min substring
                // As some extra characters can be attached from right
                // If you are thinking to choose windoEnd for determining length
                int currLen = windowEnd - windowStart + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    minStart = windowStart;
                }

                // Decreasing character from left
                if(--sHash[s[windowStart]] < tHash[s[windowStart]])
                    neededChars++;

                // Increasing window
                ++windowStart;
            }
        }

        // If minLen == INT_MAX, i.e. we have never found any substring
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
         
    }
};