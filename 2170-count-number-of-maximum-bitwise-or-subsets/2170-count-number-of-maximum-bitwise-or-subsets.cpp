class Solution {
public:

    void maximum(vector<int>& nums,vector<int>& current,int n,int &ans,vector<int>&result,int a){
        if(n>nums.size()){
            return;
        }
        else{
            for(int i=a;i<n;i++){
                current.push_back(nums[i]);
                int temp=0;
                for(int j:current){
                   temp|=j;
                }
                ans=max(ans,temp);
                result.push_back(temp);
                maximum(nums,current,n,ans,result, i+1);
                current.pop_back();
            }
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> current;
        int n=nums.size();
        int ans=0;
        int a=0;
        vector<int>result;
        maximum(nums,current,n,ans,result, a);
        int count=0;
        for(int i:result){
            if(ans==i) count++;
        }
        
        return count;
    }
};