#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    // Create a stack to store indices. +1 for an extra 0-height bar at the end.
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        // Use a dummy height of 0 at the end to flush all remaining bars from the stack
        int currentHeight = (i == heightsSize) ? 0 : heights[i];

        // While the current bar is shorter than the bar at the top of the stack,
        // we can no longer extend the rectangle of the top bar to the right.
        while (top != -1 && heights[stack[top]] >= currentHeight) {
            int h = heights[stack[top--]]; // Height of the rectangle
            // The width is the distance between the current index (right boundary)
            // and the new top of the stack (left boundary).
            int w = (top == -1) ? i : i - stack[top] - 1;
            maxArea = MAX(maxArea, h * w);
        }
        stack[++top] = i; // Push the current index onto the stack
    }

    free(stack);
    return maxArea;
}
