#include <string.h>
#include <stdlib.h>

char* simplifyPath(char* path) {
    int n = strlen(path);
    // Stack to store directory names
    char** stack = (char**)malloc(n * sizeof(char*));
    int top = 0;

    // Use strtok to split the string by '/'
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            // Go up one level: pop from stack if not empty
            if (top > 0) top--;
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            // Push valid directory name to stack
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }

    // If stack is empty, we are at root
    if (top == 0) {
        free(stack);
        return strdup("/");
    }

    // Build the result string
    char* result = (char*)malloc(n + 1);
    result[0] = '\0';
    for (int i = 0; i < top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    free(stack);
    return result;
}
