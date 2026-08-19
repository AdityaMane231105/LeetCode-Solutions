type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    // Create a cache map to store argument combinations and their results
    const cache = new Map<string, number>();
    
    return function(...args: number[]) {
        // Convert the array of arguments into a string key (e.g., [2, 3] becomes "2,3")
        const key = args.join(',');
        
        // If the key exists in the cache, return the cached result directly
        if (cache.has(key)) {
            return cache.get(key)!;
        }
        
        // Otherwise, call the original function, store the result, and return it
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
