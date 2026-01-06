class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches last node
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from end
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};