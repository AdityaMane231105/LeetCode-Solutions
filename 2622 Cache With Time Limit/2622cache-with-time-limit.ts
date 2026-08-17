class TimeLimitedCache {
    // Map stores: key -> { value, timeoutId }
    private cache: Map<number, { value: number; timeoutId: ReturnType<typeof setTimeout> }>;

    constructor() {
        this.cache = new Map();
    }
    
    set(key: number, value: number, duration: number): boolean {
        const hasKey = this.cache.has(key);
        
        // If the key already exists, clear its previous expiration timer
        if (hasKey) {
            clearTimeout(this.cache.get(key)!.timeoutId);
        }
        
        // Schedule eviction after the specified duration
        const timeoutId = setTimeout(() => {
            this.cache.delete(key);
        }, duration);
        
        // Save or update the entry in the map
        this.cache.set(key, { value, timeoutId });
        
        return hasKey;
    }
    
    get(key: number): number {
        // Since expired keys delete themselves, any key in the map is valid
        if (this.cache.has(key)) {
            return this.cache.get(key)!.value;
        }
        return -1;
    }
    
    count(): number {
        // Returns the size of the active entries map
        return this.cache.size;
    }
}
