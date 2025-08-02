class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int n = basket1.size();
        int minCost = INT_MAX;

        // Step 1: Calculate frequency difference
        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
            minCost = min({minCost, basket1[i], basket2[i]});
        }

        vector<int> extra;
        // Step 2: Collect extra fruits
        for (auto [cost, diff] : freq) {
            if (diff % 2 != 0) return -1;
            for (int i = 0; i < abs(diff) / 2; ++i) {
                extra.push_back(cost);
            }
        }

        // Step 3: Sort extra and calculate cost
        sort(extra.begin(), extra.end());
        long long cost = 0;
        for (int i = 0; i < extra.size() / 2; ++i) {
            cost += min(extra[i], 2 * minCost);
        }
        return cost;
    }
};
