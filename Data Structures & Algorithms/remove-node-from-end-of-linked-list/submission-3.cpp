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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        for (int i = 0; i < n; ++i) {
            if (cur == nullptr) {
                return nullptr;  // list.len < n
            }
            cur = cur->next;
        }
        if (cur == nullptr) {
            return head->next;  // remove head
        }
        ListNode* prev = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
