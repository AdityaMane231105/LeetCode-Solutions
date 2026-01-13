/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    // 1. Handle edge cases: empty list, single node, or k=0
    if (!head || !head->next || k == 0) {
        return head;
    }

    // 2. Count the length and find the actual tail node
    struct ListNode* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // 3. Optimize rotation: k may be much larger than length
    k = k % length;
    if (k == 0) {
        return head; // No rotation needed
    }

    // 4. Connect tail to head to form a circular list
    tail->next = head;

    // 5. Find the new tail position: (length - k - 1) steps from original head
    struct ListNode* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }

    // 6. The node after newTail is the new head
    struct ListNode* newHead = newTail->next;
    
    // 7. Break the circular link to return a proper linked list
    newTail->next = NULL;

    return newHead;
}
