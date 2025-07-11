class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int a = i + 1;
            int b = n - 1;

            while (a < b) {
                int sum = nums[i] + nums[a] + nums[b];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[a], nums[b]});
                    a++;
                    b--;

                    // Skip duplicates for a and b
                    while (a < b && nums[a] == nums[a - 1]) a++;
                    while (a < b && nums[b] == nums[b + 1]) b--;

                } else if (sum < 0) {
                    a++;
                } else {
                    b--;
                }
            }
        }

        return ans;
    }
};
