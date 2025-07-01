class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int ans=INT16_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>ans){
                ans=sum;
            }
            if(sum<0){
                sum=0;
            }
            
        }
             return ans;
        
    }
};