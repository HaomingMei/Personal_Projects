/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        // Loop through to create the Node and set the *next first
       
        // A -> A' - > B - > B' -> nullptr Formation

        Node* prev = head;
        Node* nextOriginal = nullptr;
        Node * newNode = nullptr;
        while(prev != nullptr){
            newNode = new Node(prev->val);
            nextOriginal = prev->next;
            prev->next = newNode;
            newNode->next = nextOriginal;
            prev = nextOriginal;
        }

       

        prev = head;

        // Traverse through the linked list
        // Link the primed nodes's random to previous node's random->next

        while(prev != nullptr){
            if(prev->random != nullptr){
                prev->next->random = prev->random->next;
            }
            prev = prev->next->next;  // jump to next original
        }
        // Traverse through the linked list and break the "next" links
        Node* newHead = head->next; // head of copied list
        prev = head;
        Node* current = newHead;
        while(prev != nullptr){
            prev->next = current->next;                       
            current->next = (current->next ? current->next->next : nullptr); 
            prev = prev->next;                                
            current = current->next;
        }

        return newHead;
    }
};