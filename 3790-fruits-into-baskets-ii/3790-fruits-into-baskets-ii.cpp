class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=baskets.size();
        
        for(int i:fruits){
           for(int j=0;j<baskets.size();j++){
    
             if(i<=baskets[j]){
                ans--;
                    baskets[j]=0;
                    break;
                }
            
            
           }
        }
        
        return ans;
    }
};