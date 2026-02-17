int mySqrt(int x) {
    if (x < 2) return x; // Handle 0 and 1 cases immediately

    int low = 1, high = x;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Use long long for the product to prevent overflow
        // since x can be up to 2^31 - 1
        long long square = (long long)mid * mid;

        if (square == x) {
            return mid;
        } else if (square < x) {
            ans = mid;     // Store mid as the floor value
            low = mid + 1; // Try for a larger value
        } else {
            high = mid - 1; // Value is too large
        }
    }
    
    return ans;
}
