class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;

        int pivot = -1;

        // Step 1: Find pivot (rightmost element smaller than its next)
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                pivot = i-1;
                break;
            }
        }

        // Step 2: If no pivot found, reverse (last permutation → first permutation)
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the rightmost element greater than pivot
        for(int i = n-1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
