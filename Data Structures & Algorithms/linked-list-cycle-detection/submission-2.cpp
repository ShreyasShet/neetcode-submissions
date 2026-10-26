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
        if (head != nullptr) {
            ListNode* t = head;
            ListNode* prev = nullptr;
            while(t->next != nullptr) {
                prev = t;
                t = t->next;
                if (prev->val >= t->val) {
                    if (t->next == nullptr)
                        return false;
                    return true;
                }
            }
        }
        return false;
    }
};
