/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const result = {};

    // Step 1: Add all items from arr1 to the result map
    for (const obj of arr1) {
        result[obj.id] = { ...obj };
    }

    // Step 2: Merge or add items from arr2
    for (const obj of arr2) {
        if (result[obj.id]) {
            // Override keys from arr1 with keys from arr2
            Object.assign(result[obj.id], obj);
        } else {
            result[obj.id] = { ...obj };
        }
    }

    // Step 3: Convert values to an array and sort by id ascending
    return Object.values(result).sort((a, b) => a.id - b.id);
};
