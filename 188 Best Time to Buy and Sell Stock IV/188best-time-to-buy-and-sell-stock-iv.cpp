class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // Optimization: If k allows unlimited transactions, 
        // accumulate all upward price movements (Greedy approach).
        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        // DP state arrays tracking max balance for up to k transactions
        // buy[i] stores the max capital after buying for the i-th time
        // sell[i] stores the max profit after selling for the i-th time
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                // Update buy state: either keep previous state or buy at current price using profit from previous transaction
                buy[i] = max(buy[i], sell[i - 1] - price);
                // Update sell state: either keep previous state or sell current stock to realize profit
                sell[i] = max(sell[i], buy[i] + price);
            }
        }

        return sell[k];
    }
};
