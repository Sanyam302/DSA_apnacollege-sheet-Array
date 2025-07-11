class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3) return ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // If nums[i] is positive, sum can't be zero any more
            if (nums[i] > 0) break;

            // Skip duplicate 'i' values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    ++l; --r;
                    // Skip duplicates for l and r
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
                else if (sum < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ans;
    }
};

