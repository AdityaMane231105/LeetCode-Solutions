// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    
    while (left < right) {
        // Prevent overflow: instead of (left + right) / 2
        int mid = left + (right - left) / 2;
        
        if (isBadVersion(mid)) {
            // If mid is bad, the first bad version is mid or to the left
            right = mid;
        } else {
            // If mid is good, the first bad version must be to the right
            left = mid + 1;
        }
    }
    
    // When left == right, we've found the first bad version
    return left;
}
