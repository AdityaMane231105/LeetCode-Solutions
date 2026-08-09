/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    // Return false if the classFunction is invalid, or if the object is null/undefined
    if (obj === null || obj === undefined || typeof classFunction !== 'function') {
        return false;
    }

    // Convert primitives to their object wrappers to access their prototype chain
    let currentProto = Object.getPrototypeOf(Object(obj));
    
    // Walk up the prototype chain
    while (currentProto !== null) {
        if (currentProto === classFunction.prototype) {
            return true;
        }
        currentProto = Object.getPrototypeOf(currentProto);
    }
    
    return false;
};
