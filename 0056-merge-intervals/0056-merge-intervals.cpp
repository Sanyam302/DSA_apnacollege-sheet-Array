class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.empty()) return arr;
        
        // Sort intervals by starting time
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            vector<int>& l = ans.back();
            if (arr[i][0] <= l[1]) {
                // Overlap: merge intervals
                l[1] = max(arr[i][1], l[1]);
            } else {
                // No overlap: push new interval
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};
