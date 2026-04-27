/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // If the lists intersect, ptrA and ptrB will meet at the intersection node.
        // If they don't intersect, they will both reach nullptr at the same time.
        while (ptrA != ptrB) {
            // Move to next node or switch to the head of the other list
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        return ptrA;
    }
};
