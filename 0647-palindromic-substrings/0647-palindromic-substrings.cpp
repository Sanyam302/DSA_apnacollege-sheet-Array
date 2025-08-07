class Solution {
public:
void palindrome(string s,int &ans,int i,int j){
    if(i<0 || j>s.size()-1) return;
    while(i>=0 && j<s.size() && s[i]==s[j]){
        ans++;
        i--;
        j++;

    }
}
    int countSubstrings(string s) {
       int ans;
      if(s.empty()) return 0;
      ans=0;
      for(int i=0;i<s.size();i++){
        palindrome( s, ans, i, i);
        palindrome( s, ans, i, i+1);
      }
      return ans; 
    }
};