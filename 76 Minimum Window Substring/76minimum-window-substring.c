#include <string.h>
#include <limits.h>
#include <stdlib.h>

char* minWindow(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    if (m < n) return "";

    int map[128] = {0};
    for (int i = 0; i < n; i++) map[t[i]]++;

    int left = 0, right = 0, minLen = INT_MAX, start = 0, required = n;

    while (right < m) {
        // If s[right] is needed, decrement required count
        if (map[s[right]] > 0) required--;
        map[s[right]]--; // Map becomes negative for extra characters
        right++;

        // When window is valid, try to shrink from left
        while (required == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            map[s[left]]++;
            // If map becomes positive, we lost a character from 't'
            if (map[s[left]] > 0) required++;
            left++;
        }
    }

    if (minLen == INT_MAX) return "";

    // Allocate memory for result and null-terminate
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}

