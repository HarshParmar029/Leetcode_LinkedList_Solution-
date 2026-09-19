/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = sum / 10;

        struct ListNode *n = malloc(sizeof(struct ListNode));
        n->val = sum % 10;
        n->next = NULL;

        if (!head) head = tail = n;
        else tail = tail->next = n;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return head;
}
