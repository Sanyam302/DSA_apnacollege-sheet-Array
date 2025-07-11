class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int maxP=nums[0];
         int minP=nums[0];
         int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(maxP,minP);
            maxP=max(nums[i],maxP*nums[i]);
            minP=min(nums[i],minP*nums[i]);
            ans=max(ans,maxP);
        }
        return ans;

    }
};