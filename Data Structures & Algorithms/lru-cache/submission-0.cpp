class LRUCache {
    private:
    struct Node{
        Node* prev;
        Node* next;
        int key, val;
        Node(int k, int v){
            key= k;
            val =v;
            prev=next=nullptr;
        }

    };

    unordered_map<int, Node*> mp;
        int cap;
        Node* head;
        Node* tail;

        void remove(Node* node){
            node->prev->next = node -> next;
            node->next->prev=  node -> prev;
        }
        void insert(Node* node){
            node->next= head->next;
            node->prev= head;
            head->next->prev= node;
            head->next= node;

        }


public:
    LRUCache(int capacity) {
        cap= capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next=tail;
        tail ->prev = head;
        
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* node= mp[key];
            remove(node);
            insert(node);
        return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node= mp[key];
            node->val = value;
            remove(node);
            insert(node);
        
        }
        else{
            if(mp.size()==cap){
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node=new Node(    key, value);
            mp[key] = node;
                insert(node);
        }


        
    }
};
