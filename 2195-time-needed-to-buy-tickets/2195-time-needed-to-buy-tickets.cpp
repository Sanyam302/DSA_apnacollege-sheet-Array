class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
      int ans=0;
      for(int i=0;i<t.size();i++){
        if(i<=k){
        if(t[i]>t[k]) ans+=t[k];
        else ans+=t[i];
        }
        else{
          if(t[i]>t[k]-1) ans+=t[k]-1;
        else ans+=t[i];  
        }
      }

        
        return ans;
        
    }
};