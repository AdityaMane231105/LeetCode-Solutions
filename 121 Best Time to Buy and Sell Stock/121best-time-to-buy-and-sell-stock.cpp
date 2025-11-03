class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // track minimum price so far
        int maxProfit = 0;       // track maximum profit

        for (int price : prices) {
            if (price < minPrice)
                minPrice = price;          // found a new minimum
            else if (price - minPrice > maxProfit)
                maxProfit = price - minPrice; // found a better profit
        }
        return maxProfit;
    }
};