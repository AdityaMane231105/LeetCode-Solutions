class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node before head
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Loop while there are at least two nodes to swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev two steps ahead
            prev = first;
        }

        return dummy.next;
    }
};