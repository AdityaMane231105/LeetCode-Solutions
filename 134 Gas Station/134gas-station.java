class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalSurplus = 0; // Total gas - total cost
        int currentSurplus = 0; // Gas in tank for the current segment
        int startStation = 0;

        for (int i = 0; i < gas.length; i++) {
            int netChange = gas[i] - cost[i];
            totalSurplus += netChange;
            currentSurplus += netChange;

            // If tank drops below zero, the current startStation won't work.
            // Reset to the next station and clear current tank.
            if (currentSurplus < 0) {
                startStation = i + 1;
                currentSurplus = 0;
            }
        }

        // If total gas >= total cost, the starting station found is valid.
        return (totalSurplus < 0) ? -1 : startStation;
    }
}
