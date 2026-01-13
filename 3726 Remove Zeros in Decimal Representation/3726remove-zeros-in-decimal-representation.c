long long removeZeros(long long n) {
    long long result = 0;
    long long multiplier = 1;

    while (n > 0) {
        int digit = n % 10; // Extract the last digit
        
        if (digit != 0) {
            // Add the non-zero digit to the result at the correct place value
            result = digit * multiplier + result;
            multiplier *= 10;
        }
        
        n /= 10; // Move to the next digit
    }

    return result;
}
