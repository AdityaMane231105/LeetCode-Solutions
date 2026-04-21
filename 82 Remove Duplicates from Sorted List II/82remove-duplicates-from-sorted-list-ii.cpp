class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to act as the predecessor of the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != nullptr) {
            // Check if current node is the start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes that have the same value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link 'prev' to the node after the last duplicate
                prev->next = head->next;
            } else {
                // No duplicate found, just move the 'prev' pointer forward
                prev = prev->next;
            }
            // Move 'head' forward
            head = head->next;
        }

        return dummy->next;
    }
};
