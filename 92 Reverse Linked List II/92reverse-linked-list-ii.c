/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    // 1. Create a dummy node to handle head cases
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // 2. Move prev to the node just before the 'left' position
    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    // 3. 'tail' is the first node of the segment to be reversed
    struct ListNode* tail = prev->next;

    // 4. Perform the reversal in one pass
    for (int i = 0; i < right - left; i++) {
        struct ListNode* temp = tail->next;
        tail->next = temp->next;    // Remove temp from its current spot
        temp->next = prev->next;    // Point temp to the current start of reversed segment
        prev->next = temp;          // Move temp to the front of the segment
    }

    return dummy.next;
}
