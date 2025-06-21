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
        ListNode *prevPtr = head;
        if(head== NULL || prevPtr->next == NULL) // 1 case
        {
            return head;
        }
        ListNode *currPtr = prevPtr->next;
        ListNode *nextPtr = currPtr->next;

        prevPtr -> next = NULL;
        currPtr->next= prevPtr;
        if(nextPtr == NULL) // 2 case
        {
            currPtr->next = prevPtr;
            prevPtr ->next = NULL;
            return currPtr;
        }
        else // more than 2 case
        {
            while(nextPtr->next != NULL)
            {
                // Shift all points to the right once
                prevPtr = currPtr;
                currPtr= nextPtr;
                nextPtr = currPtr->next;

                // Link
                currPtr->next = prevPtr;
            }
        }
        

        // Link the last elements of the original to previous and return as the head

        nextPtr ->next = currPtr;
        return nextPtr;
    }
};