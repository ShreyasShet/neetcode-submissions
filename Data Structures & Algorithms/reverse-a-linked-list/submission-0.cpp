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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        if (head != nullptr){
            while (head != nullptr) {
                ListNode* t = head;
                head = head->next;
                t->next = nullptr;
                t->next = newHead;
                newHead = t;
            }
        }
        return newHead;
    }
};
