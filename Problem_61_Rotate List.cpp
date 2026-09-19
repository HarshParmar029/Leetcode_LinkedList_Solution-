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
    public ListNode rotateRight(ListNode head, int k) {
        // Step 1: Edge cases
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // Step 2: Find length and last node
        ListNode temp = head;
        int len = 1;
        
        while (temp.next != null) {
            temp = temp.next;
            len++;
        }

        // Step 3: Make it circular
        temp.next = head;

        // Step 4: Effective rotations
        k = k % len;

        // Step 5: Find new tail (len - k - 1)
        int stepsToNewTail = len - k - 1;
        ListNode newTail = head;

        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail.next;
        }

        // Step 6: Set new head
        ListNode newHead = newTail.next;

        // Step 7: Break the circle
        newTail.next = null;

        return newHead;
    }
}
