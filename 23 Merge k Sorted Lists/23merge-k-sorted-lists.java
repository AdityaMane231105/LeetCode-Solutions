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
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;

        // Min-Heap based on the node's value
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Add the head of each non-empty list to the heap
        for (ListNode list : lists) {
            if (list != null) {
                pq.add(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!pq.isEmpty()) {
            // Get the smallest node from the heap
            ListNode smallest = pq.poll();
            tail.next = smallest;
            tail = tail.next;

            // If the extracted node has a next node, add it to the heap
            if (smallest.next != null) {
                pq.add(smallest.next);
            }
        }

        return dummy.next;
    }
}
