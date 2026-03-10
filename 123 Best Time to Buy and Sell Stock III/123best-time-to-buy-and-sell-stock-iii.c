#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    // We track 4 states:
    // buy1: min price to pay for the 1st stock
    // profit1: max profit after selling the 1st stock
    // buy2: min effective cost for the 2nd stock (price minus profit from 1st)
    // profit2: max total profit after selling the 2nd stock

    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        // First transaction
        if (prices[i] < buy1) buy1 = prices[i];
        if (prices[i] - buy1 > profit1) profit1 = prices[i] - buy1;

        // Second transaction
        // We treat profit1 as a "discount" for the second buy
        if (prices[i] - profit1 < buy2) buy2 = prices[i] - profit1;
        if (prices[i] - buy2 > profit2) profit2 = prices[i] - buy2;
    }

    return profit2;
}
