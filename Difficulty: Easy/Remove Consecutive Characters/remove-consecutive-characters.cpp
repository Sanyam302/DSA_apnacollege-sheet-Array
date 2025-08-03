class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        string ans="";
        ans+=s[0];
        
        for(int i=1;i<s.size();i++){
           if(s[i-1]!=s[i]){
               ans+=s[i];
           } 
        }
        return ans;
    }
};