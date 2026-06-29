class Node {
    public:
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v),prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    int capacity=0;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        left = new Node(0,0);
        right = new Node(0,0);
        left->next=right;
        right->prev=left;
        this->capacity=capacity;    
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next=next;
        next->prev=prev;
    }

    void insert(Node* node){
        Node* prev=right->prev;
        prev->next=node;
        node->next=right;
        node->prev=prev;
        right->prev=node;
    }
    
    int get(int key) {
        if(cache.count(key)>0){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.count(key)>0){
            remove(cache[key]);
        }
        Node* newNode = new Node(key,value);
        cache[key]= newNode;
        insert(newNode);
        if(cache.size()>capacity){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
