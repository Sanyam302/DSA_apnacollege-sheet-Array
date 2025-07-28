class Solution {
public:
    int maxOr = 0;
    int count = 0;

    void dfs(vector<int>& nums, int index, int orValue) {
        if (index == nums.size()) {
            if (orValue == maxOr) count++;
            return;
        }

        // Include nums[index]
        dfs(nums, index + 1, orValue | nums[index]);

        // Exclude nums[index]
        dfs(nums, index + 1, orValue);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Step 1: Calculate max possible OR
        for (int num : nums) {
            maxOr |= num;
        }

        // Step 2: Use DFS to count subsets reaching maxOr
        dfs(nums, 0, 0);
        return count;
    }
};
