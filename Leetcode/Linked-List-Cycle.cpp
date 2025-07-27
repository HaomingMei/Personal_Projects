/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Using a fast & slow pointer approach
        // Fast will always be behind or overlap slow pointer if there is a cycle
        // Since there will not reach a endpoint.
        ListNode* slow =head;
        ListNode* fast =head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow ->next;
            fast = fast->next->next;
            if((fast!= nullptr)&&(slow==fast || fast->next == slow)){
                return true;
            }
        }
        return false;
    }
};