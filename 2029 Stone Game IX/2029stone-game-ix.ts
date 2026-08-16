function stoneGameIX(stones: number[]): boolean {
    const count = [0, 0, 0];
    
    // Group stones by their remainders modulo 3
    for (const stone of stones) {
        count[stone % 3]++;
    }
    
    // Scenario 1: Even number of 0-stones
    if (count[0] % 2 === 0) {
        return count[1] > 0 && count[2] > 0;
    }
    
    // Scenario 2: Odd number of 0-stones
    return Math.abs(count[1] - count[2]) > 2;
}
