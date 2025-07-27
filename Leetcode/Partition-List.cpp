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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* leftList = new ListNode(0, nullptr);
        ListNode* rightList = new ListNode(0, nullptr);
        ListNode* leftTemp = leftList;
        ListNode* rightTemp = rightList;
        ListNode* temp1 = head;

        while(temp1 != nullptr){
            if(temp1->val < x){
                leftTemp -> next = temp1;
                leftTemp = leftTemp ->next;
            }
            else{
                rightTemp-> next = temp1;
                rightTemp = rightTemp->next;

            }
            temp1 = temp1->next;
        }
        leftTemp -> next = rightList->next;
        rightTemp -> next = nullptr;
        //delete leftTemp;
       // delete rightTemp
        return leftList->next;

    }
};