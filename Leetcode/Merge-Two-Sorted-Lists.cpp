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
        if(list1== NULL && list2 == NULL)
        {
            return NULL;
        }
        else if(list1==NULL  )
        {
            return list2;
        }
        else if( list2== NULL)
        {
            return list1;
        }
        else{
           ListNode* curr1Ptr = list1;
           ListNode* curr2Ptr = list2;
           ListNode* newList = new ListNode();
           ListNode* tempPtr = newList;

           while(curr1Ptr!= NULL && curr2Ptr!= NULL)
           {
               int curr1Value = curr1Ptr->val;
               int curr2Value = curr2Ptr->val;
               if(curr1Value == curr2Value)
               {
                   // Equal case:
                   // Put Linked List 1's node on default then Linked list 2's second
                   if(tempPtr == NULL)
                   {
                       tempPtr = new ListNode(curr1Ptr->val);
                       tempPtr->next = new ListNode(curr2Ptr->val);
                   }
                   else{
                       tempPtr->next = new ListNode(curr1Ptr->val);
                       tempPtr = tempPtr->next;
                       tempPtr->next = new ListNode(curr2Ptr->val);
                   }
                  
                   tempPtr = tempPtr->next;
                   curr1Ptr = curr1Ptr ->next;
                   curr2Ptr = curr2Ptr ->next;
               }
               else if(curr1Value > curr2Value)
               {
                   if(tempPtr == NULL)
                   {
                       tempPtr = new ListNode(curr2Ptr->val);
                   }
                   else{ // 
                       tempPtr->next = new ListNode(curr2Ptr->val);
                       tempPtr = tempPtr ->next;
                   }

                   curr2Ptr = curr2Ptr ->next;

               }
               else{
                   if(tempPtr == NULL)
                   {
                       tempPtr = new ListNode(curr1Ptr->val);
                   }
                   else{ // 
                       tempPtr->next = new ListNode(curr1Ptr->val);
                       tempPtr = tempPtr ->next;
                   }
                    curr1Ptr = curr1Ptr ->next;
                  
               }
           }
           while(curr1Ptr != NULL)
           {
               // Apend the rest
                tempPtr->next = new ListNode(curr1Ptr->val);
                tempPtr = tempPtr ->next;
                curr1Ptr = curr1Ptr ->next;
           }

           while(curr2Ptr!=NULL)
           {
               tempPtr->next = new ListNode(curr2Ptr->val);
                tempPtr = tempPtr ->next;
                curr2Ptr = curr2Ptr ->next;
           }
           return newList->next;
        }
    }
};