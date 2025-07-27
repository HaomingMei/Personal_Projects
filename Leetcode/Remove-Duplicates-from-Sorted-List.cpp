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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head ;
        // Since all the node values are sorted, the only possible duplicate is the nodes
        // Is the next to the current one


        // Approach: Traverse and update the current node's next to the next's next
        // until the value is different
        while(temp != nullptr && temp->next != nullptr){
            if(temp->next->val == temp->val){
                temp->next = temp->next->next;
                continue;
            }
            temp = temp ->next;
        }
        return head;
    }
};