function memoize(fn) {
    const cache = new Map()
    return function(...args) {
        let current = cache
        for (let i = 0; i < args.length; i++) {
            if (!current.has(args[i])) {
                current.set(args[i], new Map())
            }
            current = current.get(args[i])
        }
        if (current.has('result')) {
            return current.get('result')
        }
        const result = fn(...args)
        current.set('result', result)
        return result
    }
}
