class Solution {
public:
    void subSet(vector<int> &arr, int target, vector<int> &temp, int i, int n, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == n || target < 0) return;

        // Include arr[i] (can reuse)
        temp.push_back(arr[i]);
        subSet(arr, target - arr[i], temp, i, n, ans); // stay at i to allow reuse
        temp.pop_back();

        // Exclude arr[i]
        subSet(arr, target, temp, i + 1, n, ans); // move to next
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end()); // remove duplicate numbers
        subSet(arr, target, temp, 0, arr.size(), ans);
        return ans;
    }
};
