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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        
        if (list2 == nullptr)
            return list1;

        ListNode* merge = nullptr;
        ListNode* head = nullptr;
        
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* temp;
            if (list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            } else {
                temp = list2;
                list2 = list2->next;
            }

            temp->next == nullptr;

            if (head == nullptr) {
                head = temp;
                merge = temp;
            } else {
                merge->next = temp;
                merge = temp;
            }
        }

        if (list1 != nullptr)
            merge->next = list1;
        else
            merge->next = list2;

        return head;
    }
};
