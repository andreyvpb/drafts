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
    bool hasCycle(ListNode* head) {
        ListNode *curX1 = head;
        ListNode *curX2 = head;
        while (curX2 != nullptr) {
            curX1 = curX1->next;
            curX2 = curX2->next;
            if (curX2 == nullptr) {
                return false;
            }
            curX2 = curX2->next;
            if (curX2 == curX1) {
                return true;
            }
        }
        return false;
    }
};
