class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.empty()) return arr;
        
        // Sort intervals by starting time
        sort(arr.begin(), arr.end());

       int r=0;

        for (int i = 1; i < arr.size(); i++) {
            
            if (arr[i][0] <= arr[r][1]) {
                // Overlap: merge intervals
                arr[r][1] = max(arr[i][1], arr[r][1]);
            } else {
                r++;
                arr[r]=arr[i];
            }
        }

        return vector<vector<int>>(arr.begin(), arr.begin() + r + 1);

    }
};
