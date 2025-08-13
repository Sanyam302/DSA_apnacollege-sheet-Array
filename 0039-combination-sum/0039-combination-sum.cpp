class Solution {
public:
  set<vector<int>>s;
   void subSet(vector<int>&arr, int target,vector<int>&temp,int i,int n,vector<vector<int>>&ans){
     if(i==n || target<0){
        return;
     }
     if(target==0){
        if(s.find(temp)==s.end()){
          ans.push_back(temp);
          s.insert(temp);
        }
        
        return;
     }
     
     temp.push_back(arr[i]);
     
     subSet(arr, target-arr[i],temp,i,n,ans);
     temp.pop_back();
     subSet(arr, target,temp,i+1,n,ans);
   }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
       vector<int>temp;
       vector<vector<int>>ans;
       int i=0;
       int n=arr.size(); 
       sort(arr.begin(),arr.end());
       subSet(arr, target,temp,i,n,ans);
       return ans;
    }
};