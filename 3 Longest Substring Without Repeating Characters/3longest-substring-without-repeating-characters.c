#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int left = 0;
    
    // Array to store the last seen index of each character (ASCII 0-127)
    // Initialize with -1 to indicate character hasn't been seen yet
    int lastSeen[128];
    for (int i = 0; i < 128; i++) lastSeen[i] = -1;

    for (int right = 0; right < n; right++) {
        unsigned char currentChar = s[right];

        // If character was seen within current window, move 'left' pointer
        if (lastSeen[currentChar] >= left) {
            left = lastSeen[currentChar] + 1;
        }

        // Update last seen position and calculate window size
        lastSeen[currentChar] = right;
        maxLength = MAX(maxLength, right - left + 1);
    }

    return maxLength;
}
