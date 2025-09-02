class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
             int a=-1;
             int p=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    a=j;
                    break;
                }
            }
             if(a!=-1){
            for(int z=a+1;z<nums2.size();z++){
                if(nums2[z]>nums2[a]){ p=nums2[z];break;}

            }
            ans.push_back(p);
             }
             else{
                ans.push_back(p);
             }
        }

        return ans;
    }
};