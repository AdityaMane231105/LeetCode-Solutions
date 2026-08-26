/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeoutId;
    
    return function(...args) {
        // Clear any existing active timer to reset the delay window
        clearTimeout(timeoutId);
        
        // Setup a new timer to execute the function after 't' milliseconds
        timeoutId = setTimeout(() => {
            fn(...args);
        }, t);
    };
};
