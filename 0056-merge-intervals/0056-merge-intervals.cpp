class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.empty()) return arr;
        if(arr.size()==1) return arr;
        sort(arr.begin(),arr.end(),[](vector<int>a,vector<int>b){
            return a[0]<b[0];
        });
        vector<vector<int>>ans;
        ans.push_back({arr[0][0],arr[0][1]});
        int n=arr.size();
        
        for(int i=0;i<n;i++){
           vector<int>&l=ans.back();
           if(arr[i][0]<=l[1]){
            l[1]=max(arr[i][1],l[1]);
           }
            
            else{
            ans.push_back(arr[i]);
        } 
        }
       
        
        return ans;
    }
};