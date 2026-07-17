/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle empty list or single-node list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* current = head;
        
        // Traverse the list
        while (current != nullptr && current->next != nullptr) {
            // If the current value matches the next value, skip the next node
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free up memory to prevent leaks
            } else {
                // Otherwise, move to the next unique node
                current = current->next;
            }
        }
        
        return head;
    }
};
