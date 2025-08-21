class Node{ // Using a doubly linked list structure
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    int cap;

    std::unordered_map<int, Node*> mp; // Each Position points to the respective node (ordered by most recently used from left to right)
    Node * head = nullptr;
    Node* tail = nullptr;
    //std::deque<int> q;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0); // Use two dummy nodes
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto find = mp.find(key);
        if(find != mp.end()){ // Can find it

            // MOVe it to the front
            Node* prevNode = find->second->prev;
            Node* nextNode = find->second->next;
            prevNode->next = nextNode; // Connect the one before to the one after
            nextNode->prev = prevNode; // connect the one after to the one before

            find->second->next = head->next; // Insert node right after dummy head
            head->next->prev = find->second; // Connect new node to the old front
            head->next = find->second;       // Update dummy head’s next
            find->second->prev = head;       // Connect new node to the dummy head

            return find->second->val;
        }
        else{ // Not found
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto find = mp.find(key);
        if(find != mp.end()){ // If it does exist change the value, and put it at the front
            find->second->val = value; // Update the value  
            Node* prevNode = find->second->prev;
            Node* nextNode = find->second->next;
            prevNode->next = nextNode; // Connect the one before to the one after
            nextNode->prev = prevNode; // connect the one after to the one before

            find->second->next = head->next; // Insert node right after dummy head
            head->next->prev = find->second; // Connect new node to the old front
            head->next = find->second;       // Update dummy head’s next
            find->second->prev = head;       // Connect new node to the dummy head
        }
        else{ // If it did not exist
            Node* newNode = new Node(key, value);
            if(mp.size() == cap){ // If size is at cap, remove then insert
                Node* temp = tail->prev;    // The LRU node
                int oldKey = temp->key;     // Save its key before removal
                temp->prev->next = tail;
                tail->prev = temp->prev;
                mp.erase(oldKey);           // Erase the node to be removed from the hash map
                delete temp;

                newNode->next = head->next; // Insert new node at front
                head->next->prev = newNode; 
                head->next = newNode;
                newNode->prev = head;

                mp[key] = newNode; // Add to hashmap
            }
            else{ // Otherwise, just insert
                newNode->next = head->next; // Insert new node at front
                head->next->prev = newNode; 
                head->next = newNode;
                newNode->prev = head;

                mp[key] = newNode; // Add to hashmap
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
