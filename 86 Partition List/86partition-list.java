/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        // Initialize two dummy nodes to anchor the new sub-lists
        ListNode lessHead = new ListNode(0);
        ListNode greaterHead = new ListNode(0);
        
        // Pointers to the current tail of the two lists
        ListNode less = lessHead;
        ListNode greater = greaterHead;
        
        // Traverse the original list
        while (head != null) {
            if (head.val < x) {
                less.next = head; // Add to "less than" list
                less = less.next;
            } else {
                greater.next = head; // Add to "greater or equal" list
                greater = greater.next;
            }
            head = head.next;
        }
        
        // Terminate the greater list to avoid cycles
        greater.next = null;
        
        // Connect the two lists: less-than tail -> greater-than head
        less.next = greaterHead.next;
        
        // Return the start of the re-ordered list (skipping the dummy)
        return lessHead.next;
    }
}
