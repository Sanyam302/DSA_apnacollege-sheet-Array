class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
      for(int i=0;i<n-2;i++){
        int a=i+1;
        int b=n-1;
        while(a<b){
            if(arr[a]+arr[b]==-arr[i]){
                vector<int>t={arr[i],arr[a],arr[b]};
                if(s.find(t)==s.end()){
                    s.insert(t);
                    ans.push_back(t);
                }
                a++;
                b--;
                
            }
            else if(arr[a]+arr[b]>-arr[i]) b--;
                else a++;
        }
      }  
      return ans;
    }
};