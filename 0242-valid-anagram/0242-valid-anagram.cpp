class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return 0;
       vector<int>count(26,0);
       vector<int>count2(26,0);
       for(int i=0;i<s.length();i++){
        count[s[i]-'a']++;
        count2[t[i]-'a']++;
       }
       return count==count2;
    }
};