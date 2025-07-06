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

        //* Find the Midpoint using Slow and Fast Pointer Techniques
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) // Ensures that the Split is EVen
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* secondHalf = slow->next;
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        //* Reverse the Secondhalf Singly Linked List
        while(secondHalf != nullptr){
            temp = secondHalf->next;
            secondHalf -> next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }
        //* Merge the two together
        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        ListNode* first = head;
        secondHalf = prev;
            // prev is the next head of the reversed secondhalf
        while(secondHalf != nullptr  ){ // ensure that we stop at the right node
            temp1 = first->next;
            temp2 = secondHalf->next;

            secondHalf->next = temp1;
            first->next = secondHalf;

            first = temp1;
            secondHalf = temp2;
           // if(secondHalf->next == nullptr){
            //    break;
          //  }
        }

        // Return the head
    
        
    }
};