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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* ptr = head;
        int nth = 1;

        if(head->next == nullptr)
        {
            return head->next;
        }

        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
            nth++;
        }

        if(n == nth)
        {
            return head->next;
        }

        int index = nth - n - 1;

        ptr = head;

        while(index != 0)
        {
            ptr = ptr->next;
            index--;
        }

        ptr->next = ptr->next->next;

        return head;

    }

};
