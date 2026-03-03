#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    
    // Allocate max_len + 2: 
    // +1 for a possible carry at the front, +1 for '\0'
    char* res = (char*)malloc((max_len + 2) * sizeof(char));
    res[max_len + 1] = '\0'; // Null terminator at the very end
    
    int i = len_a - 1;
    int j = len_b - 1;
    int k = max_len; // Pointer for the result string
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        res[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }
    
    // If the loop finished and k is still 0, it means we used the extra carry space.
    // If k is 0, the first character (res[0]) was never filled.
    if (k == 0) {
        return &res[1]; // Skip the unused first byte
    }
    
    return res;
}
