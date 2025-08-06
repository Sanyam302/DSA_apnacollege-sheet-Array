class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>curr;
        int ans=0;
        int maximum=0;
        for(char i:s){
           if(find(curr.begin(),curr.end(),i)!=curr.end()){
            
                curr.erase(curr.begin(),find(curr.begin(),curr.end(),i)+1);
            
            curr.push_back(i);
        
           }
           else{
curr.push_back(i);
    
           }
           ans=max(ans,(int)curr.size());
        }
        return ans;
    }
};