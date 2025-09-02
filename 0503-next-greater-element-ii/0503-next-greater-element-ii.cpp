class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>ans;
        int n=nums.size()-1;
        int j;
        for( j=n;j>=0;j--){
           while(!s.empty()&& s.top()<=nums[j]) s.pop();
        
        if(!s.empty()){
            ans.push_back(s.top());
            
        }
        else{
            for(int i=0;i<j;i++){
                if(nums[i]>nums[j]){
                    s.push(nums[i]);
                    ans.push_back(nums[i]);
                    
                    break;
                }
            }
            if(s.empty()) ans.push_back(-1);
            
        }
        s.push(nums[j]);
        }
         reverse(ans.begin(),ans.end());
         return ans;

    }
};