class node{
    public:
        int key; int val;
        int count;
        node* next;
        node* prev;

        node(int key, int val){
            this->key = key;
            this->val = val;
            count = 1;
            next = nullptr;
            prev = nullptr;
        }

    };
    class llist{
        public:
        int size;
        node* head;
        node* tail;

        llist(){
            head = new node(0, 0);
            tail = new node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addnode(node* newnode){
            node* temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
            size++;
        }

        void removenode(node* delnode){
            if (delnode == nullptr || delnode == head || delnode ==tail){
                return;
            } 
            node* delprev = delnode->prev;
            node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };


class LFUCache {

    map<int, node*> keynode;
    map<int, llist*> freqlistmap;
    int maxsizecache;
    int minfreq;
    int currsize;

public:

    
    LFUCache(int capacity) {
        maxsizecache = capacity;
        minfreq = 0;
        currsize = 0;
    }

    void updatefreqlistmap(node* n){
        keynode.erase(n->key);
        freqlistmap[n->count]->removenode(n);
        if(n->count == minfreq && freqlistmap[n->count]->size == 0){
            minfreq++;
        }
        llist* higherfreqlist = new llist();
        if(freqlistmap.find(n->count+1)!=freqlistmap.end()){
            higherfreqlist = freqlistmap[n->count+1];
        }
        else {
            freqlistmap[n->count + 1] = higherfreqlist;
        }
        n->count ++;
        higherfreqlist->addnode(n);
        keynode[n->key] = n;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            node* n = keynode[key];
            int val = n->val; 
            updatefreqlistmap(n);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsizecache == 0){
            return;
        }
        if(keynode.find(key)!=keynode.end()){
            node* n = keynode[key];
            n->val = value;
            updatefreqlistmap(n);
        }
        else{
            if(currsize == maxsizecache){
                llist* l = freqlistmap[minfreq];
                keynode.erase(l->tail->prev->key);
                freqlistmap[minfreq]->removenode(l->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq = 1;
            llist* listfreq = new llist();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                listfreq = freqlistmap[minfreq];
            }
            else {
                freqlistmap[minfreq] = listfreq;
            }
            node* n = new node(key, value);
            listfreq->addnode(n);
            keynode[key] = n;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
