class LRUCache {

    struct Node {
        int val=-1;
        int key=-1;
        Node* next, *prev;
    };
    Node* head, *tail;
    unordered_map<int, Node*> cache;
    int cap, curr;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = tail = NULL;
        curr=0;
    }
    


    void moveToEnd(Node* node) {
        if(!node) {
            return;
        }
        if(tail == node) {
            return;
        }
        
        if(head == node) {
            head = head->next;
        }
        if(!head) {
            head = node;
        }


        if(node->next != NULL) {
            
            node->next->prev = node->prev;
        }
        cout<<"here1";
        if(node->prev) {
            node->prev->next = node->next;
        }

        if(tail && tail!=node)
            tail->next = node;
        
        node->prev = tail;
        tail = node;
        node->next = NULL;
    }

    void deleteFromList() {
        if(head==NULL) {
            return;
        }

        cache.erase(head->key);
        if(head == tail) {
            tail = tail->next;
        }
        head = head->next;

        delete(head->prev);
        head->prev = NULL;
        
    }

    int get(int key) {
        
        if(cache.count(key)==0) {
            return -1;
        }
        
        Node* node = cache[key];
        
        moveToEnd(node);
        return node->val;
    }
    
    void put(int key, int value) {
        cout<<"here2";
        Node* node = cache[key];
        if(node == NULL) {
            node = new Node();
            cache[key]=node;
            curr++;
        }
        node->val = value;
        node->key = key;

        moveToEnd(node);
        if(curr > cap) {
            deleteFromList();
            curr--;
        }
    }
};
