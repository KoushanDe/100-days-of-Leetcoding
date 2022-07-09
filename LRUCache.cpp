class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        
        Node* prev;
        Node* next;
        
        Node(int k,int v){
            key=k;
            val=v;
        }
    };
    
    void addNewnode(int key,int value)
    {
        Node* newnode = new Node(key,value);
        Node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
        hashmap[key] = newnode;
    }
    
    int deleteOldnode(int key)
    {
        Node* oldnode = hashmap[key];
        oldnode->prev->next = oldnode->next;
        oldnode->next->prev = oldnode->prev;
        int value = oldnode->val;
        delete(oldnode);
        return value;
    }
    
    void deleteLastnode()
    {
        Node* lastnode = tail->prev;
        lastnode->prev->next = tail;
        tail->prev = lastnode->prev;
        hashmap.erase(lastnode->key);
        delete(lastnode);
    }
    
    int k=0;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> hashmap;
    
    LRUCache(int capacity) {
        k = capacity;
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(hashmap.find(key)==hashmap.end())
            return -1;
        
        else{
            int value = deleteOldnode(key);
            
            addNewnode(key,value);
            
            return value;
        }
    }
    
    void put(int key, int value) {
        
        if(hashmap.find(key)==hashmap.end())
        {   
            if(hashmap.size()==k)
            {
                deleteLastnode();
            }
            
            addNewnode(key,value);
        }
        else{
            deleteOldnode(key);
            
            addNewnode(key,value);
        } 
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */