class DoublyLLNode {
public:
    int key;
    int value;
    DoublyLLNode* next;
    DoublyLLNode* prev;

    DoublyLLNode(int k, int v) {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, DoublyLLNode*> mp;
    DoublyLLNode* head;
    DoublyLLNode* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }

private:
    void updatePosition(DoublyLLNode* node) {
        if(node == tail) return;
        if(node == head) head = head->next;
            
        // Break LL if already exists
        if(node->prev != NULL) {
            node->prev->next = node->next;
        }
        if(node->next != NULL) {
            node->next->prev = node->prev;
        }
        node->prev = NULL;
        node->next = NULL;

        // Attach new node at the end of LL 
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    
public:
    int get(int key) {
        bool alreadyExists = mp.count(key) > 0;
        if(!alreadyExists) return -1;
        updatePosition(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        // Check if key already exists
        bool alreadyExists = mp.count(key) > 0;
        DoublyLLNode* node = alreadyExists ? mp[key] : new DoublyLLNode(key, value);
         
        if(alreadyExists) {
            node->value = value;
            updatePosition(node);
        }
        else {
            // Check if LRUCache has reached the capacity 
            if(mp.size() >= capacity) {
                // delete LRU cache  
                mp.erase(head->key);
                if(head == tail) { // Case of capacity = 1
                    delete head;
                    head = NULL;
                    tail = NULL;
                }
                else {
                    DoublyLLNode* temp = head->next;
                    head->next = NULL;
                    temp->prev = NULL; 
                    delete head;
                    head = temp;
                }
            }
            
            if(head == NULL) head = node;
            else {
                // Connect node at tail of LL 
                tail->next = node;
                node->prev = tail;
            }
            // Update the tail and map 
            tail = node;
            mp[key] = node;
        }
    }
};
