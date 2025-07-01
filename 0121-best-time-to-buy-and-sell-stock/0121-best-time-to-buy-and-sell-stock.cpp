class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPrice = INT32_MAX;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            ans = max(ans, price - minPrice);
        }

        return ans;
    }
};