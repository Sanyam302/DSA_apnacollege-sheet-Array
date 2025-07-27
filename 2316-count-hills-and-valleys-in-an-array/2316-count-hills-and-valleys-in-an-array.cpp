class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i] == nums[i-1]) continue;
            int j=i+1;
            int k=i-1;
            while(k>=0){
                if(nums[k]!=nums[i]){
                    break;

                }
                k--;
            }
             while(j<n){
                if(nums[j]!=nums[i]){
                    break;

                }
                j++;
             }
             if(j<n && k>=0){
                if((nums[j]>nums[i] && nums[k]>nums[i])||(nums[j]<nums[i] && nums[k]<nums[i])){
                ans++;
             }}
            }
            return ans;
    }
};