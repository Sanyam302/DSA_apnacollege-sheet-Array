class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);   // store answers aligned to indices

        for (int j = 2*n - 1; j >= 0; j--) {
            int idx = j % n;

            // pop all smaller/equal elements
            while (!s.empty() && s.top() <= nums[idx]) {
                s.pop();
            }

            if (j < n) { // only fill results in first pass
                if (!s.empty()) ans[idx] = s.top();
                else ans[idx] = -1;
            }

            s.push(nums[idx]);
        }

        return ans;
    }
};
