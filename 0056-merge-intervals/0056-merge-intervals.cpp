class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty()) return ans;

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 2: Start with the first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = ans.back();  // last merged interval

            if (intervals[i][0] <= last[1]) {
                // Overlapping → merge
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap → push new interval
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};