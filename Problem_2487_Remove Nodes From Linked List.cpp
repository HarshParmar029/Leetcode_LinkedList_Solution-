class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Reverse the list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        // Remove nodes smaller than the maximum seen so far
        int maxVal = 0;
        curr = head;
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        while (curr) {
            if (curr->val >= maxVal) {
                maxVal = curr->val;

                if (newHead == nullptr) {
                    newHead = curr;
                    tail = curr;
                } else {
                    tail->next = curr;
                    tail = curr;
                }
            }

            curr = curr->next;
        }

        tail->next = nullptr;

        // Reverse again
        prev = nullptr;
        curr = newHead;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
