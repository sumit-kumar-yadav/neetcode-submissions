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

        // detach node
        if(node == head) {
            head = head->next;
            if(head) head->prev = NULL;
        }
        else {
            node->prev->next = node->next;

            if(node->next)
                node->next->prev = node->prev;
        }

        // attach at tail
        node->next = NULL;
        node->prev = tail;

        tail->next = node;
        tail = node;
    }

public:

    int get(int key) {

        if(mp.count(key) == 0)
            return -1;

        DoublyLLNode* node = mp[key];

        updatePosition(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.count(key)) {

            DoublyLLNode* node = mp[key];

            node->value = value;

            updatePosition(node);

            return;
        }

        // capacity full
        if(mp.size() >= capacity) {

            DoublyLLNode* temp = head;

            mp.erase(temp->key);

            head = head->next;

            if(head)
                head->prev = NULL;

            if(temp == tail)
                tail = NULL;

            delete temp;
        }

        DoublyLLNode* node = new DoublyLLNode(key, value);

        if(head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        mp[key] = node;
    }
};