class Solution {
public:
    bool participate(vector<int>& nums, int sum, int ind, vector<vector<int>>& dp){
        if(sum == 0) return true;                // target reached
        if(sum < 0 || ind == nums.size()) return false;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        // include nums[ind]
        bool include = participate(nums, sum - nums[ind], ind + 1, dp);

        // exclude nums[ind]
        bool exclude = participate(nums, sum, ind + 1, dp);

        return dp[ind][sum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums) sum += n;
        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return participate(nums, target, 0, dp);
    }
};
