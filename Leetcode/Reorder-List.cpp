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
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next== NULL)
        {
            return;
        }
        // Find mid Point with slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        if(slow->next == fast && fast->next == NULL)
        {
            return;
        }
        while(fast->next != NULL)
        {
            slow = slow->next;
            if(fast->next->next == NULL)
            {
                fast = fast->next;
            }
            else{
                fast = fast->next->next;
            }
            
        }
        ListNode* temp = slow->next;
        slow ->next = nullptr;
        // Reverse the slow nodes to fast nodes,
        ListNode* prevPtr = nullptr;
        ListNode* nextPtr = temp;
        
        while(temp != fast)
        {
            temp = temp->next;
            nextPtr-> next = prevPtr;
            prevPtr = nextPtr;
            nextPtr = temp;
            
        }
        fast->next= prevPtr;

        // Traverse both Linked List
        ListNode* left = head;
        ListNode* tempLeft = NULL;
        ListNode* tempRight = NULL;
        while(fast != NULL)
        {
            if(left->next != NULL)
            {
                tempLeft = left->next;
            }
            else{
                tempLeft->next = tempRight;
                break;
            }
            if(fast->next !=NULL)
            {
                tempRight = fast->next;
            }
            else{
                left->next = fast;
                fast->next = tempLeft;
                break;
            }
            left->next = fast;
            fast->next = tempLeft;
            fast = tempRight;
            left = tempLeft;
        }
        
    }
   
};