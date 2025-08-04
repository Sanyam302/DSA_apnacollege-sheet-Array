class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans="";
         sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
   
    for(int i=0;i<strs[0].size();i++){
        char c=strs[0][i];
        for(int j=1;j<strs.size();j++){
            char a=strs[j][i];
            if(c!=a) return ans;
        }
        ans+=c;
    }
    return ans;
    }
};