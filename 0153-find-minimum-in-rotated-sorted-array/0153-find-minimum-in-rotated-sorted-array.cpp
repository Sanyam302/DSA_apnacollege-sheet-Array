class Solution {
public:
    int findMin(vector<int>& nums) {
       int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            // If mid element is greater than the rightmost, min is on the right
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                // Minimum is on the left side including mid
                r = mid;
            }
            
        }
        return nums[l];
    }
};