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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* head = nullptr;

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        if(l1->val <= l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }

        ListNode* it = head;

        while (l1 != nullptr || l2 != nullptr)
        {
            if(l1 == nullptr && l2 != nullptr)
            {
                it->next = l2;
                l2 = l2->next;
                it = it->next;
                continue;
            }
            
            if(l1 != nullptr && l2 == nullptr)
            {
                it->next = l1;
                l1 = l1->next;
                it = it->next;
                continue;
            }

            if(l1->val <= l2->val)
            {
                it->next = l1;
                l1 = l1->next;
                it = it->next;
            }
            else
            {
                it->next = l2;
                l2 = l2->next;
                it = it->next;
            }

        }

        return head;

    }

};
