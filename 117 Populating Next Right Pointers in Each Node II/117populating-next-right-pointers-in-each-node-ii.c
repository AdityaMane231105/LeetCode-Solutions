struct Node* connect(struct Node* root) {
    if (!root) return NULL;

    struct Node* currLevel = root; // Start with the root level

    while (currLevel) {
        struct Node dummy = {0, NULL, NULL, NULL}; // Temporary head for the next level
        struct Node* currChild = &dummy;

        // Traverse the current level horizontally
        while (currLevel) {
            if (currLevel->left) {
                currChild->next = currLevel->left;
                currChild = currChild->next;
            }
            if (currLevel->right) {
                currChild->next = currLevel->right;
                currChild = currChild->next;
            }
            // Move to the next node in the current level
            currLevel = currLevel->next;
        }

        // Move down to the start of the level we just stitched together
        currLevel = dummy.next;
    }

    return root;
}
