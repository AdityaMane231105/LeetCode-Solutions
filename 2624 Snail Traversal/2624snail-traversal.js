/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    // Return an empty array if the dimensions do not match the element count
    if (rowsCount * colsCount !== this.length) {
        return [];
    }

    // Initialize the 2D matrix structure
    const result = Array.from({ length: rowsCount }, () => []);

    let elementIndex = 0;

    // Traverse column by column
    for (let col = 0; col < colsCount; col++) {
        if (col % 2 === 0) {
            // Even columns: Move from top to bottom
            for (let row = 0; row < rowsCount; row++) {
                result[row][col] = this[elementIndex++];
            }
        } else {
            // Odd columns: Move from bottom to top
            for (let row = rowsCount - 1; row >= 0; row--) {
                result[row][col] = this[elementIndex++];
            }
        }
    }

    return result;
};

/**
 * const arr =;
 * arr.snail(1,4); // [[1,2,3,4]]
 */
