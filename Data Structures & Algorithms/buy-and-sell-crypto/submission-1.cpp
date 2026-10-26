class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0, L = 0, R = 1;

        while (R < n) {
            int profit = prices[R] - prices[L];

            if (profit > max_profit)
                max_profit = profit;

            if (profit >= 0)
                R++;
            else {
                L = R;
                R++;
            }
        }

        return max_profit;
    }
};
