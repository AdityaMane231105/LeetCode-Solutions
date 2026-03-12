struct Node *map[101]; // Global or helper map to track cloned nodes

struct Node* dfs(struct Node* s) {
    if (s == NULL) return NULL;

    // If we already cloned this node, return the existing clone
    if (map[s->val] != NULL) {
        return map[s->val];
    }

    // Create a new node (the clone)
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    
    // Allocate memory for the clone's neighbors list
    if (clone->numNeighbors > 0) {
        clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * clone->numNeighbors);
    } else {
        clone->neighbors = NULL;
    }

    // Store it in the map BEFORE recursing to handle cycles
    map[s->val] = clone;

    // Recursively clone all neighbors
    for (int i = 0; i < s->numNeighbors; i++) {
        clone->neighbors[i] = dfs(s->neighbors[i]);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    // Reset map for every new test case
    for (int i = 0; i < 101; i++) map[i] = NULL;
    return dfs(s);
}
