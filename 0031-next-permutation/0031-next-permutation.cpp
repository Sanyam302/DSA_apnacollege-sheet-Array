class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1) return;

        int pivot=-1;
        \
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int index;
        for(int i=n-1;i>pivot;i--){
            if(nums[i]>nums[pivot]){
               index=i;
               break;
            }
        }
        swap(nums[pivot],nums[index]);
        sort(nums.begin()+pivot+1,nums.end());
        return;
    }
};