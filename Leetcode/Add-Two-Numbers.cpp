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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;

        ListNode* temp2 = l2;
        int carry = 0;
        if(temp1->val + temp2->val >= 10){
            carry = 1;
                     // the carry from the previous node / position
        }
        ListNode* current = new ListNode((temp1->val + temp2->val)%10);
        ListNode* head = current;
        int i = 0;
        temp1 = temp1->next;
        temp2 = temp2->next;
        while(temp1 != nullptr || temp2 != nullptr){
            ListNode *newNode = new ListNode();
            std::cout << "Iteration Number: " << i << std::endl;
            //std::cout << "Temp1: " << temp1->val << std::endl;
           // std::cout << "Temp2: " << temp2->val << std::endl;
            if( (temp1 == nullptr)&& temp2){ // temp1 is shorter than temp 2 case
                std::cout << "First condition" << std::endl;
                newNode->val = (temp2->val + carry) %10;
                if((temp2->val + carry)>= 10){
                    carry = 1;
                }
                else{
                    carry = 0;
                }
                temp2 = temp2->next;
            }
            else if((temp2 == nullptr) && temp1){ // Temp2 is shorter than temp1 case 
                std::cout << "Second condition" << std::endl;

                newNode->val = (temp1->val + carry) %10;
                std::cout << "New node value: " << newNode->val << std::endl;
                if((temp1->val + carry)>= 10){
                    carry = 1;
                }
                else{
                    carry = 0;
                }
                temp1 = temp1->next;

            }
            else{ // Value still exist for both
                std::cout << "Third condition" << std::endl;
                newNode->val = (temp1->val + temp2->val + carry) %10;
                
                if((temp1->val + temp2->val + carry)>= 10){
                    carry = 1;
                }
                else{
                    carry = 0;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        
            current -> next = newNode; // List the previous node to new node
            current = current->next;   // Update
            i++;
        }
        if(carry == 1){ // Overflow
            current->next = new ListNode(1);

        }
        return head;


        
    }
};