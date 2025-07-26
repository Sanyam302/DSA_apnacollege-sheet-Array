class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        
        int n = arr.size();
        int maxL = 0;
        int sum = 0;
        unordered_map<int,int> map;
        
        for(int i=0; i<n; i++){
            
            sum = ((sum + arr[i]) % k + k)%k;
            
            if(sum == 0){
                maxL = i+1;
            }
            else if(map.find(sum) != map.end()){
                maxL = max(maxL,i-map[sum]);
            }else{
                map[sum] = i;
            }
        }
        return maxL;
    }
};


