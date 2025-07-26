class Solution {
public:
vector<vector<int>>result;
   void mid(int n,int k,vector<int>&sum,int i){
       if(sum.size()==k){
        result.push_back(sum);
        return;
       }
       for(int idx=i;idx<n+1;idx++){
         sum.push_back(idx);
         mid(n,k,sum,idx+1);
         sum.pop_back();
       }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>sum;
        mid(n,k,sum,1);
        return result;
    }

};