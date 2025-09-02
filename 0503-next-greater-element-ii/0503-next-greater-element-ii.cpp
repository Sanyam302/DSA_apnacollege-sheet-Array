class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for(int j = n - 1; j >= 0; j-- ){
            s.push(nums[j]);
        }  

        for (int j = n - 1; j >= 0; j--) {
            int idx = j;

            // pop all smaller/equal elements
            while (!s.empty() && s.top() <= nums[idx]) {
                s.pop();
            }

            // only fill results in first pass
                if (!s.empty()) ans[idx] = s.top();
            
            

            s.push(nums[idx]);
        }

        return ans;
    }
};
