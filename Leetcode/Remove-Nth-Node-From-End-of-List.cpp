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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Count number of nodes we traversed as N
        // nth from the End is just the N - n. Meaning we travel N-n-1 nodes, and cut if off from there
        // This approach takes O(2*n), which is O(n)
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* root = head;
        ListNode* curr = head;
        int count = 1;
        while(curr->next != nullptr){
            curr= curr ->next;
            count += 1;
        }
       // std::cout << "My BEFORE count is " << count << std::endl;
        curr = root;
     
        count = count -n; // Number of nodes to travel
        //std::cout << "My count is " << count << std::endl;
        ListNode* prev = nullptr;

        while(count != 0){
            prev = curr;
            curr = curr->next;
            count -= 1;
        }
        if(prev != nullptr){
            prev->next = curr->next;
        }else{ 
            prev = curr;
            curr = curr->next;
            return curr;
        }
        return root;


    }
};