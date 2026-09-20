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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int count = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            // Current node belongs to nums
            // and next node does not belong to nums
            if (s.count(curr->val) &&
                (curr->next == nullptr || !s.count(curr->next->val))) {
                count++;
            }

            curr = curr->next;
        }

        return count;
    }
};
