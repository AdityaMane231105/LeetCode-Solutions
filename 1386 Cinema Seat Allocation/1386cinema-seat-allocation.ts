function maxNumberOfFamilies(n: number, reservedSeats: number[][]): number {
    const rowMap = new Map<number, number>();

    // Step 1: Build the bitmask for each row
    for (const [row, seat] of reservedSeats) {
        if (seat >= 2 && seat <= 9) {
            const currentMask = rowMap.get(row) || 0;
            rowMap.set(row, currentMask | (1 << (seat - 2)));
        }
    }

    // Define bitmasks for the three valid 4-seat configurations
    const leftMask = 0b00001111;   // Seats 2, 3, 4, 5
    const middleMask = 0b00111100; // Seats 4, 5, 6, 7
    const rightMask = 0b11110000;  // Seats 6, 7, 8, 9

    // Count groups possible in fully unreserved rows
    let maxGroups = (n - rowMap.size) * 2;

    // Step 2: Check rows that have reservations
    for (const mask of rowMap.values()) {
        let count = 0;
        const leftFree = (mask & leftMask) === 0;
        const rightFree = (mask & rightMask) === 0;

        if (leftFree && rightFree) {
            count += 2;
        } else if (leftFree || rightFree || (mask & middleMask) === 0) {
            count += 1;
        }
        
        maxGroups += count;
    }

    return maxGroups;
}
